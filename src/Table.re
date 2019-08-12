let str = ReasonReact.string;


let make = (data, s) => {

  let get = (i, j) => {
    let v = Debt.get(data, i+1, j+1);
    str(Util.f2s(v^));
  };
  
  let td = (i, j) => {
    <td style=Style.td> {get(i,j)} </td>
  };

  <table style = s>
      
            <thead style=Style.h>
              <tr style=Style.h>
                <th style=Style.tc1> {str("Who paid:")} </th>
                <th style=Style.h> {str("for Irene")} </th>
                <th style=Style.h> {str("for Andrey")} </th>
                <th style=Style.h> {str("for  Nicola")} </th>
              </tr>
            </thead>
            <tbody style=Style.tbody>
              <tr style=Style.tr>
                <th style=Style.tc1> {str("Irene")} </th>
                {td(0,0)}
                {td(1,0)}
                {td(2,0)}
              </tr>
              <tr style=Style.tr>
                <th style=Style.tc1> {str("Andrey")} </th>
                {td(0,1)}
                {td(1,1)}
                {td(2,1)}
              </tr>
              <tr style=Style.tr>
                <th style=Style.tc1> {str("Nicola")} </th>
                {td(0,2)}
                {td(1,2)}
                {td(2,2)}
              </tr>
              </tbody>
            </table>
};

