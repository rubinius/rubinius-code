describe "An Or node" do
  parse "(a or b)" do
    [:or, [:call, nil, :a, [:arglist]], [:call, nil, :b, [:arglist]]]
  end

  parse "((a || b) || (c && d))" do
    [:or,
     [:call, nil, :a, [:arglist]],
     [:or,
      [:call, nil, :b, [:arglist]],
      [:and, [:call, nil, :c, [:arglist]], [:call, nil, :d, [:arglist]]]]]
  end

  parse "((a or b) or (c and d))" do
    [:or,
     [:call, nil, :a, [:arglist]],
     [:or,
      [:call, nil, :b, [:arglist]],
      [:and, [:call, nil, :c, [:arglist]], [:call, nil, :d, [:arglist]]]]]
  end

  parse "() or a" do
    [:or, [:nil], [:call, nil, :a, [:arglist]]]
  end

  parse "a or ()" do
    [:or, [:call, nil, :a, [:arglist]], [:nil]]
  end
end
