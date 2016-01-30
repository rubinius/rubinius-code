describe "A Dot3 node" do
  parse "(a...b)" do
    [:dot3, [:call, nil, :a, [:arglist]], [:call, nil, :b, [:arglist]]]
  end
end
