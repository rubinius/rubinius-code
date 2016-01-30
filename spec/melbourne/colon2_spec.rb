describe "A Colon2 node" do
  parse "X::Y" do
    [:colon2, [:const, :X], :Y]
  end
end
