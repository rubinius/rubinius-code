describe "A Return node" do
  parse "return" do
    [:return]
  end

  parse "return 1" do
    [:return, [:lit, 1]]
  end

  parse "return *1" do
    [:return, [:splat, [:lit, 1]]]
  end

  parse <<-ruby do
      x = 1, 2
      return *x
    ruby

    [:block,
      [:lasgn, :x, [:array, [:lit, 1], [:lit, 2]]],
      [:return, [:splat, [:lvar, :x]]]]
  end

  parse "return 1, 2, 3" do
    [:return, [:array, [:lit, 1], [:lit, 2], [:lit, 3]]]
  end

  parse "return 1, 2, *c" do
    [:return,
     [:argscat, [:array, [:lit, 1], [:lit, 2]], [:call, nil, :c, [:arglist]]]]
  end

  parse "return [*[1]]" do
    [:return, [:splat, [:array, [:lit, 1]]]]
  end

  parse "return *[1]" do
    [:return, [:splat, [:array, [:lit, 1]]]]
  end
end
