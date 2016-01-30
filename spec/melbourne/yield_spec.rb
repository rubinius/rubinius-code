describe "A Yield node" do
  parse "yield(42, 24)" do
    [:yield, [:lit, 42], [:lit, 24]]
  end

  parse "yield([42, 24])" do
    [:yield, [:array, [:lit, 42], [:lit, 24]]]
  end

  parse "yield([42])" do
    [:yield, [:array, [:lit, 42]]]
  end

  parse "yield([])" do
    [:yield, [:array]]
  end

  parse "yield(42)" do
    [:yield, [:lit, 42]]
  end

  parse "yield" do
    [:yield]
  end

  parse "yield([*[]])" do
    [:yield, [:array, [:splat, [:array]]]]
  end

  parse "yield([*[1]])" do
    [:yield, [:array, [:splat, [:array, [:lit, 1]]]]]
  end

  parse "yield([*[1, 2]])" do
    [:yield, [:array, [:splat, [:array, [:lit, 1], [:lit, 2]]]]]
  end

  parse "yield(*[1])" do
    [:yield, [:splat, [:array, [:lit, 1]]]]
  end

  parse "yield(*[1, 2])" do
    [:yield, [:splat, [:array, [:lit, 1], [:lit, 2]]]]
  end
end
