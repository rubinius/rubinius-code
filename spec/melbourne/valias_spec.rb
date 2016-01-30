describe "A Valias node" do
  parse "alias $y $x" do
    [:valias, :$y, :$x]
  end
end
