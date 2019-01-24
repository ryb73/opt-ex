open Belt.Option;

let some = (v) => Some(v);

let flatten = fun
    | Some(o) => o
    | None => None;

let defaultDelayed = (defaultFn, opt) =>
    switch opt {
        | Some(v) => v
        | None => defaultFn()
    };

let mapDefaultDelayed = (mapFn, defaultFn, opt) =>
    opt
    |> map(_, mapFn)
    |> defaultDelayed(defaultFn);

module Operators = {
    let (|?) = getWithDefault;
};
