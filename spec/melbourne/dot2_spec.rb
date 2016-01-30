describe "A Dot2 node" do
  parse "(a..b)" do
    [:dot2, [:call, nil, :a, [:arglist]], [:call, nil, :b, [:arglist]]]
  end
end
