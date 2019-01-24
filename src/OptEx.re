open Belt.Option;

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
