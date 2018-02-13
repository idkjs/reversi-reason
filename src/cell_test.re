open Jest;
open Enzyme;
open Expect;

configureEnzyme(react_16_adapter());

describe("<Cell />", () => {
    test("should render a disk with the right identifier", () => {
        let test = (color, expectedClass) => {
            let wrapper = shallow(
                <Cell
                    color
                    onClick=((_) => ())
                />
            );

            expect(wrapper |> find(expectedClass) |> length) |> toBe(1);
        };

        test(Some(Cell.Black), ".disk.black");
        test(Some(Cell.White), ".disk.white");
        test(None, ".disk");
    });
});