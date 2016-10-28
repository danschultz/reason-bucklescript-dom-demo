let module Date = {
  external now : unit => int = "Date.now" [@@bs.val];
};

let module Event = {
  type t;
  external preventDefault : t => (unit => unit) => unit = "preventDefault" [@@bs.send];
};

let module Element = {
  type t;
  external querySelector : string => t = "querySelector" [@@bs.send.pipe: t];
  external querySelectorAll : t => string => list t = "querySelectorAll" [@@bs.send];
  external addEventListener : string => (Event.t => unit) => t = "addEventListener" [@@bs.send.pipe: t];
};

let module Document = {
  type t;
  external querySelector : string => Element.t = "document.querySelector" [@@bs.val];
  external querySelectorAll : string => list Element.t = "document.querySelectorAll" [@@bs.val];
};

let module Window = {
  let document () : Document.t => [%bs.raw "window.document"];
  external requestAnimationFrame : _ => int = "window.requestAnimationFrame" [@@bs.val];
  external cancelAnimationFrame : int => unit = "window.cancelAnimationFrame" [@@bs.val];
};
