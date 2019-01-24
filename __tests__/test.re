open Jest;
open Expect;
open OptEx;

describe("defaultDelayed", () => {
    test("Some", () => {
        Some(1)
        |> defaultDelayed(() => failwith("Shouldn't execute"))
        |> expect |> toBe(1);
    });

    test("None", () => {
        None
        |> defaultDelayed(() => 2)
        |> expect |> toBe(2);
    });
});

describe("mapDefaultDelayed", () => {
    test("Some", () => {
        Some(1)
        |> mapDefaultDelayed((*)(2), () => failwith("Shouldn't execute"))
        |> expect |> toBe(2);
    });

    test("None", () => {
        None
        |> mapDefaultDelayed((*)(2), () => 4)
        |> expect |> toBe(4);
    });
});
