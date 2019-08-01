type t = {
  ts: (string, string),
  date: string,
  value: float,
  type_: Expense.t,
  paidby: Person.t,
};

let data_test_json_gist : list(t) = [
//  url = "https://gist.github.com/kowaraj/e9070badf374c1fd8fd97d6bda6804cb"
    
//  {date: "2666-66-66", value: 66.66,  type_: EdF,      paidby: Andrey, ts: ("2666-66-66", "2666-66-66")}, // <-- fake bill: ? subscription fee?
];

let data : list(t) = [

  //test data, set #1
  /* {date: "2017-10-10", value: 3000., type_: EdF,      paidby: Andrey, ts: ("2017-11-01", "2017-12-01")}, */
  /* {date: "2017-10-11", value: 600.,  type_: EdF,      paidby: Irene,  ts: ("2017-11-01", "2017-12-01")}, */

  //real data

  {date: "2016-11-08", value: 56.20,  type_: EdF,      paidby: Andrey, ts: ("2016-11-01", "2016-11-02")}, // <-- fake bill: ? subscription fee?
  {date: "2016-11-08", value: 64.00,  type_: EdF,      paidby: Andrey, ts: ("2016-11-06", "2016-11-07")}, // fake ts
  {date: "2017-02-17", value: 655.00, type_: EdF,      paidby: Andrey, ts: ("2017-02-15", "2017-02-16")}, // fake ts
  {date: "2017-04-11", value: 511.00, type_: EdF,      paidby: Andrey, ts: ("2017-04-09", "2017-04-10")}, // fake ts
  {date: "2017-05-28", value: 247.65, type_: EdF,      paidby: Andrey, ts: ("2017-06-10", "2017-06-11")}, // fake ts

  {date: "2017-07-30", value: 64.6,   type_: Internet, paidby: Irene,  ts: ("2017-06-01", "2017-07-31")},
  {date: "2017-07-30", value: 172.24, type_: EdF,      paidby: Andrey, ts: ("2017-05-01", "2017-07-31")},
  {date: "2017-09-30", value: 150.00, type_: Internet, paidby: Irene,  ts: ("2017-08-01", "2017-10-31")},
  {date: "2017-09-26", value: 174.33, type_: EdF,      paidby: Andrey, ts: ("2017-08-01", "2017-08-31")},

  {date: "2017-11-26", value: 330.55, type_: EdF,      paidby: Andrey, ts: ("2017-09-01", "2017-10-31")},
  {date: "2018-02-06", value: 109.21, type_: EdF,      paidby: Andrey, ts: ("2017-11-01", "2018-01-31")},
  {date: "2018-03-27", value: 391.25, type_: EdF,      paidby: Andrey, ts: ("2018-02-01", "2018-02-28")},
  {date: "2018-05-27", value: 193.47, type_: EdF,      paidby: Andrey, ts: ("2018-03-01", "2018-04-30")},
  {date: "2018-09-01", value: 362.78, type_: Internet, paidby: Irene,  ts: ("2017-11-01", "2018-09-30")},
  // all equal on 2018-09-13

  {date: "2018-08-16", value: 144.32, type_: EdF,      paidby: Andrey, ts: ("2018-05-28", "2018-07-27")},
  {date: "2018-09-26", value: 141.17, type_: EdF,      paidby: Andrey, ts: ("2018-07-28", "2018-09-26")},
  {date: "2018-11-26", value: 256.08, type_: EdF,      paidby: Andrey, ts: ("2018-09-27", "2018-11-26")},
  {date: "2019-02-08", value: 538.06, type_: EdF,      paidby: Andrey, ts: ("2018-11-27", "2019-01-27")},
  {date: "2019-03-12", value: 164.90, type_: Internet, paidby: Irene,  ts: ("2018-11-01", "2019-03-01")},


];

let str = (x) => {
  "Bill: " ++ Util.f2s(x.value)
    ++ " @" ++ x.date
    ++ " (" ++ Expense.str(x.type_) ++ ")"
    ++ Util.t2s(x.ts)
    ++ " - " ++ Person.name(x.paidby)
};

let print = (x) => {
  Js.log( str(x) );
};

let dump = () => { 

Js.log("List of Bills: ");  List.map(x=>print(x), data) |> ignore;  Js.log(" ");

};
