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

describe("bindNone", () => {
    test("Some", () => {
        Some(1)
        |> bindNone(() => failwith("Shouldn't execute"))
        |> expect |> toBe(Some(1));
    });

    test("None", () => {
        None
        |> bindNone(() => Some(2))
        |> expect |> toBe(Some(2));
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

describe("bindNoneDelayed", () => {
    test("Some", () => {
        Some(1)
        |> bindNoneDelayed((*)(2), () => failwith("Shouldn't execute"))
        |> expect |> toBe(Some(2));
    });

    test("None", () => {
        None
        |> bindNoneDelayed((*)(2), () => Some(4))
        |> expect |> toBe(Some(4));
    });
});
