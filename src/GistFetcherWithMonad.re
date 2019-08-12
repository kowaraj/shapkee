let str = ReasonReact.string;

type state =
  | NotAsked
  | Loading
  | Failure
  | Success(list(Bill.t));

module Decode = {

  let ts_decoder = ts_json => {
    Json.Decode.pair(Json.Decode.string, Json.Decode.string, ts_json);
  }
  let type_decoder = type_json => {
    Expense.ctor(Json.Decode.string(type_json))
  }
  let paidby_decoder = paidby_json => {
    Person.ctor(Json.Decode.string(paidby_json))
  }
  
  open Bill;
  let bill_decoder = bill_json => {
      Json.Decode.{
        ts: field("ts", ts_decoder, bill_json),
        date: field("date", string, bill_json),
        value: field("value", Json.Decode.float, bill_json),
        type_: field("type_", type_decoder, bill_json),
        paidby: field("paidby", paidby_decoder, bill_json)
      }
  }
  let bills = json : list(Bill.t) => {
    Json.Decode.list(bill_decoder, json);
  }

};

module PromiseMonad = {
  let defer = (f):Js.Promise.t('a) => Js.Promise.make((~resolve,~reject as _) => ignore(f(resolve)));
  let return = (a: 'a) : Js.Promise.t('a) => Js.Promise.resolve(a);
  let (>>=) = (m: Js.Promise.t('a), f: 'a => Js.Promise.t('b))
              => Js.Promise.then_(f, m);
};

let fetchBills = (url) => {
  Js.log(url)
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_( json => json |> Decode.bills |> (bs => { Js.log("!!!"); Js.log(bs); Some(bs) } |> resolve) )
    |> catch( { _err => {Js.log(_err); resolve(None)} })
  )};

type action =
  | LoadUsers
  | LoadedUsers(list(Bill.t))
  | LoadUsersFailed;

let component = ReasonReact.reducerComponent("FetchComponent");


let make = (~url, _children) => {
  ...component,
  initialState: () => NotAsked,
  reducer: (action, _state) =>
    switch (action) {
    | LoadUsers =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              fetchBills(url)
              |> then_(result => {
                  Js.log(result)
                   switch (result) {
                   | Some(bills) => {
                     resolve(self.send(LoadedUsers(bills)))
                     }
                   | None => resolve(self.send(LoadUsersFailed))
                   }
                    }
                 )
              |> ignore
            )
        ),
      )
    | LoadedUsers(bills) => ReasonReact.Update(Success(bills))
    | LoadUsersFailed => ReasonReact.Update(Failure)
    },
  render: self =>
    switch (self.state) {
    | NotAsked => 
      <div>
        <p> {str("Click the button below to fetch the list of bills from gist.github.com!")} <br/>
            {str("The URL is: " ++ url)} </p>
        (str("Click to fetch Bills  "))
        <button onClick=(_event => self.send(LoadUsers))>
          (str("Load Bills"))
        </button>
      </div>
    | Loading => <div> (str("Loading...")) </div>
    | Failure => <div> (str("Something went wrong!")) </div>
    | Success(bills : list(Bill.t)) => {

          let calcs2 = Calc.main2(bills);
          let t1 = Table.make(calcs2.dtable1, Style.table);
          let t2 = Table.make(calcs2.dtable2, Style.table2);

          <div>

            <div hidden=true>
              <p> {str("Format of the tables below is the following:")} </p>
              <p> {str("The rows are people who paid the bills FOR everybody. The columns show how much was paid for whom.");} </p>
              <p style=Style.t1> {str("After all the bills have been paid:");} </p>
              <p> {str("(accumulative table, never zeroed down):");} </p>
              t1
              <p> {str("*");} </p>
            </div>

            <p style=Style.t1 > {str("Accounted for all the payback transactions:");} </p>
            <p> {str("(should be all zeros when 'all squared'.)");} </p>
            t2
          </div>;
        }
    },
};

