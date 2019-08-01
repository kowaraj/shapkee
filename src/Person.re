type t =
  | Nobody
  | Irene
  | Andrey
  | Nicola;

let ctor = (s : string) => {
  switch (s) {
    | "Andrey" => Andrey
    | "Irene" => Irene
    | "Nicola" => Nicola
    | "Nobody" => Nobody
    | _ => Nobody
  }
}

let name = (p : t) => {
  switch (p){
  | Nobody => "nobody"
  | Andrey => "Andrey"
  | Irene => "Irene"
  | Nicola => "Nicola"
  }
};

let id = (p : t) => {
  switch (p){
  | Nobody => 0
  | Irene => 1
  | Andrey => 2
  | Nicola => 3
  }
};

let names = (ps : list(t)) => { 
   String.concat(" ", List.map(p=>name(p), ps));
};
              



  
