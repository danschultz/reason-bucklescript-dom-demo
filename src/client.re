type person = {name: string, age: int};

let add a b => a + b;
let subtract a b => a - b;

let rec reduce f acc list => {
  switch list {
    | [] => acc
    | [hd, ...tl] => reduce f (f acc hd) tl
  };
};

let map f => reduce (fun list a => list @ [f(a)]) [];

let sum = reduce add 0;

let find_button = Dom.Element.querySelector ".button";
let log_click = Dom.Element.addEventListener "click" (fun e => Js.log "click");

let main => {
  let summed = sum [1, 2, 3];
  Js.log summed;

  let date = Dom.Date.now ();
  Js.log date;

  let box = Dom.Document.querySelector ".box";
  find_button box |> log_click;
};
