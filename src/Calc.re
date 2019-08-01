let get_people = (b : Bill.t) => {
  switch( List.find( (i : Occupant.t) => Util.is_in(b.ts, i.ts) , Occupant.data) ) {
  | x => List.filter( p=>p!=Person.Nobody, x.people)
  | exception Not_found => [Person.Nobody]
  };
};

let process_bill = (trlist_acc, b :Bill.t) => {
  Bill.print(b);
  let i = b.paidby;
  let pp = get_people(b);
  Js.log("_get_people: " ++ Util.t2s(b.ts) ++ " RETURN: " ++ Person.names(pp))
    
  let a = b.value /. float_of_int(List.length(pp));
  let pps = List.filter(p=>p!=b.paidby, pp);
  let trlist =  List.map(p => {  let tr : Transaction.t =
                                 {from: i,
                                  to_: p,
                                  value: a,
                                  date: "to be paid",
                                  description: string_of_float(b.value) ++ " paid @"++b.date ++ " ("++Expense.str(b.type_)++") "};
                                 tr },
                         pps);

  Transaction.print_list(trlist);
  List.append(trlist_acc, trlist);
};

let process_tr = (acc, t : Transaction.t) => {
  let x_who = List.nth(List.nth(acc, Person.id(t.to_)), Person.id(t.from));
  let x_whom = List.nth(List.nth(acc, Person.id(t.from)), Person.id(t.to_));
  x_who := x_who^ -. t.value;
  x_whom := x_whom^ +. t.value;
  acc;
};

let debts = (pp, trlist) => {
  let n = 4;

  let dt1_ref = Debt.make_ref(n);
  let dt1_ref_pass = List.fold_left( process_tr, dt1_ref, trlist);

  let dt2_ref = Debt.clone(dt1_ref_pass);
  let dt2_ref_pass = List.fold_left( process_tr, dt2_ref, Transaction.data);
  
  let ds : Debt.t = {
    dtable1: dt1_ref_pass,
    dtable2: dt2_ref_pass,
    people: pp,
  };
  ds;
};

// let cb_resolved = (x) => {
//   Js.log("cb_resolved: ")
//   Js.log(x);
//   Js.log("cb_resolved -- end.")
// }

// let test_fetch2 = () => {

//   let url2 = "https://gist.githubusercontent.com/kowaraj/f5af2adaefe33547949d4822ac09f863/raw/cdf12d7b9be573440a5fa6d9cbf0f925cd8bcb8f/test_for_reasonml2.json"

//   Js.Promise.(
//     Fetch.fetch(url2)
//     |> then_(Fetch.Response.text)
//     |> then_(text => cb_resolved(text) |> resolve)
//   )
//   |> Js.log;
// };

// let test_fetch = () => {
//   Js.Promise.(
//     FetchBasicExample.fetchUsers()
//     |> then_(result => 
//                     {
//                       Js.log("-------------- !! -------------")
//                       Js.log(result)
//                       switch (result) {
//                       | Some(users) => resolve( Js.log(users))
//                       | None => resolve( Js.log("no users") )
//                       }
//                     })
//     |> ignore
//   )

// };

let main = () => {

  Bill.dump();
  Occupant.dump();
  let tlist = List.fold_left( process_bill, [] , Bill.data);

  Transaction.dump();
  let ds : Debt.t = debts(Occupant.get_people_all(), tlist);
  
  Debt.print(ds);

  ds;
  
};

let main2 = (bills) => {


  Occupant.dump();
  let tlist = List.fold_left( process_bill, [] , bills);

  Transaction.dump();
  let ds : Debt.t = debts(Occupant.get_people_all(), tlist);
  
  Debt.print(ds);
  //test_fetch2();

  ds;
  
};



  
