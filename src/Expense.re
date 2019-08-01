type t = 
  | Internet
  | EdF
  | ERROR;

let str = (e : t) => {
  switch (e){
  | Internet => "internet"
  | EdF => "edf"
  | ERROR => "ERROR: Unknown Expense Type"
  }
};

let ctor = (n : string) => {
  switch (n) {
    | "EdF" => EdF
    | "Internet" => Internet
    | _ => ERROR
  }
}
