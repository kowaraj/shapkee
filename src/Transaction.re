type t = {
  date: string,
  value: float,
  description: string,
  from: Person.t,
  to_: Person.t,
};

let data : list(t) = [
  //test data, set #1
  /* {date: "2017-10-11", value: 800.,  description: "for edf", from: Irene,  to_: Andrey}, */
  /* {date: "2017-10-12", value: 1000., description: "for edf", from: Nicola,  to_: Andrey}, */
  /* {date: "2017-10-12", value: 200.,  description: "for edf", from: Nicola,  to_: Irene}, */

  //real data
  {date: "2017-03-20", value: 387.70,  description: "payback", from: Irene,  to_: Andrey},
  {date: "2017-04-10", value: 255.70,  description: "payback", from: Irene,  to_: Andrey},
  {date: "2017-06-11", value: 123.50,  description: "payback", from: Irene,  to_: Andrey},

  {date: "2017-11-11", value: 61.78,  description: "payback", from: Irene,  to_: Andrey},
  {date: "2017-11-11", value: 49.47,  description: "payback", from: Nicola, to_: Irene },
  {date: "2017-11-11", value: 58.11,  description: "payback", from: Nicola, to_: Andrey},

  {date: "2018-09-13", value: 220.72, description: "payback", from: Irene,  to_: Andrey},
  {date: "2018-09-13", value: 341.50, description: "payback", from: Nicola, to_: Andrey},
  {date: "2018-09-13", value: 121.40, description: "payback", from: Nicola, to_: Irene},
  // all equal on 2018-09-13

  {date: "2019-03-16", value: 304.9, description: "payback", from: Irene, to_: Andrey},
  
];

let str = (x) => {
  "Transaction: " ++ Person.name(x.from) ++ " -> " ++
    Person.name(x.to_) ++ " " ++ 
    Util.f2s(x.value) ++ " " ++ 
    " FOR: " ++ x.description;
};

let print = (x) => {
  Js.log(str(x));
};

let print_list = (l) => {
  List.map( (tr :t) => print(tr), l) |> ignore;
};

let dump = () => { Js.log("Payback Transactions: "); print_list(data); Js.log(" "); };


  // on 2019.03.12 : 
  /*
     ----------------------------------------------------------------------------
     Monthly consomation:
     
     >>> y16 = 190.+ 282.
     472.0
     >>> y17 = 294.+199.+161+106+66+67+65+65+70+96+171+226
     1586.0
     >>> y18 = 236+215+174+115+73+71+69+68+72+99+175+231
     1598.0
     >>> y19 = 242+31.
     273.0

     >>> TOTAL: y16 + y17 + y18 + y19
     3929.0

     ----------------------------------------------------------------------------
     Paid factures:
     
     >>> factures = 64+655+511+247+ 172.24+174.33+330.+109.21+391.25+193.47+362.78
     3929.0
     
     */
  
      // >>> IreneToAndrey = 387.70 + 255.70 + 123.50
      // 766.9
      // >>> AndreyPaid = 64 + 655 + 511 + 247
      // 738.5
      // >>> IreneToAndrey - AndreyPaid/2.
      // 28.399999999999977  --------------- <--- Do I owe this to Irene? 
    
