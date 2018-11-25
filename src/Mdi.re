/*
Copyright (c) 2018 Eldad Zack

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

type mdi_size =
  | Size18
  | Size24
  | Size36
  | Size48;

let size_to_string = (size: mdi_size) =>
  "mdi-"
  ++ (
    switch (size) {
    | Size18 => "18px"
    | Size24 => "24px"
    | Size36 => "36px"
    | Size48 => "48px"
    }
  );

let component = ReasonReact.statelessComponent("MDI");

let make = (~kind: MdiType.t, ~color: option(string)=?, ~extra_class: option(string)=?, ~onClick=?, ~size: mdi_size=Size24, _children) => {
  ...component,
  render: _self => {
    let className = "mdi " ++ MdiType.name(kind) ++ " " ++ size_to_string(size);

    let className =
      switch (extra_class) {
      | None => className
      | Some(extra) => className ++ " " ++ extra
      };

    let style =
      switch (color) {
      | None => None
      | Some(s) => Some(ReactDOMRe.Style.make(~color=s, ()))
      };

    <span className ?style ?onClick />;
  },
};
