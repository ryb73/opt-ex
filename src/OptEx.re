open Belt.Option;

let some = (v) => Some(v);

let flatten = fun
    | Some(o) => o
    | None => None;

let defaultDelayed = (fn) => fun
    | None => fn()
    | Some(v) => v;

let bindNone = (fn) => fun
    | None => fn()
    | _ as o => o;

let mapDefaultDelayed = (mapFn, defaultFn, opt) =>
    opt
    |> map(_, mapFn)
    |> defaultDelayed(defaultFn);

module Operators = {
    let (|?) = getWithDefault;
};
