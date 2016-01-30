describe "An And node" do
  parse "(a and b)" do
    [:and, [:call, nil, :a, [:arglist]], [:call, nil, :b, [:arglist]]]
  end

  parse "() and a" do
    [:and, [:nil], [:call, nil, :a, [:arglist]]]
  end

  parse "a and ()" do
    [:and, [:call, nil, :a, [:arglist]], [:nil]]
  end
end
