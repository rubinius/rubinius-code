describe "A Gasgn node" do
  parse "$x = 42" do
    [:gasgn, :$x, [:lit, 42]]
  end

  parse "$a = *[1]" do
    [:gasgn, :$a, [:splat, [:array, [:lit, 1]]]]
  end
end
