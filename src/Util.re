let now_ts = "2020-01-01";

let f2s = x => {
  let k = 10.;
  let xint = int_of_float(x *. k);
  string_of_float(float_of_int(xint) /. k);
};

let range = (i, j) => { 
  let rec aux = (n, acc) => {
    if (n < i) {
      acc;
    } else {
      aux( n-1, List.append([n], acc) );
    }
  };
  aux(j, []);
};

let cell = (t, i, j) => {
  List.nth(List.nth(t, j), i);
};

let t2s = (x) => {  " [" ++ fst(x) ++ ":" ++ snd(x) ++ "]" };

let is_in = ( (t1_start, t1_stop), (t2_start, t2_stop) )  => {
  let a = compare( t2_start, t1_start) === -1 || compare(t2_start, t1_start) === 0;
  let b = compare( t2_stop,  t1_stop)  ===  1 || compare(t2_stop,  t1_stop) === 0;
  let ret = a && b;
  //Js.log("? __is_in: " ++ t2s( (t1_start, t1_stop) ) ++ " is in " ++ t2s( (t2_start, t2_stop) ) ++ " == " ++ string_of_bool(ret));
  ret;    
};


