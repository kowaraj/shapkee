let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */

let calcs = Calc.main();

// let get = (p1, p2) => {
//   let v = Debt.get(calcs.dtable1, p1+1, p2+1);
//   str(Util.f2s(v^))
// };

// let get_cout = (p1, p2) => {
//   let v = Debt.get(calcs.dtable2, p1+1, p2+1);
//   str(Util.f2s(v^))
// };

let t1 = Table.make(calcs.dtable1, Style.table);
let t2 = Table.make(calcs.dtable2, Style.table2);

let make = (_children) => {
  ...component,
  initialState: () => {count: 0, show: true},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },
  
  render: _self => {

    <div hidden=false>
      <p> {str("Format of the tables below is the following:")} </p>
      <p> {str("The rows are people who paid the bills FOR everybody. The columns show how much was paid for whom.");} </p>
      <p style=Style.t1> {str("After all the bills have been paid:");} </p>
      <p> {str("(accumulative table, never zeroed down):");} </p>
      t1
      <p> {str("*");} </p>

    <p style=Style.t1 > {str("Accounted for all the payback transactions:");} </p>
    <p> {str("(should be all zeros when 'all squared'.)");} </p>
    t2

  </div>;
  },
};
