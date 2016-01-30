describe "A Gvar node" do
  parse "$x" do
    [:gvar, :$x]
  end

  parse "$stderr" do
    [:gvar, :$stderr]
  end

  parse "$__blah" do
    [:gvar, :$__blah]
  end

  parse "$_" do
    [:gvar, :$_]
  end
end
