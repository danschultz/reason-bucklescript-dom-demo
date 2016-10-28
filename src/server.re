/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */
let f () => "Hello World, Compiled from REBEL!!";

type message = {message: string};

/* let g () => Test1.my_secret; */

open Rexpress.Express;

let __dirname: Js.undefined string = [%bs.node __dirname];

let app = Express.express ();

Express.get app "/" (fun req res => Response.json res [%bs.obj {root: __dirname}]);

Express.get app "/hello" (fun req res => Response.json res [%bs.obj {message: f()}]);

Express.use app (Express.static path::"__dirname");

Express.listen app 3000;
