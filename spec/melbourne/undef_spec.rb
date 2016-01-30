describe "An Undef node" do
  parse "undef :x" do
    [:undef, [:lit, :x]]
  end

  parse "undef :x, :y" do
    [:block, [:undef, [:lit, :x]], [:undef, [:lit, :y]]]
  end

  parse "undef :x, :y, :z" do
    [:block, [:undef, [:lit, :x]], [:undef, [:lit, :y]], [:undef, [:lit, :z]]]
  end

  parse <<-ruby do
      f1
      undef :x
    ruby

    [:block, [:call, nil, :f1, [:arglist]], [:undef, [:lit, :x]]]
  end

  parse <<-ruby do
      f1
      undef :x, :y
    ruby

    [:block,
     [:call, nil, :f1, [:arglist]],
     [:undef, [:lit, :x]],
     [:undef, [:lit, :y]]]
  end

  parse <<-ruby do
      undef :x, :y, :z
      f2
    ruby

    [:block,
     [:undef, [:lit, :x]],
     [:undef, [:lit, :y]],
     [:undef, [:lit, :z]],
     [:call, nil, :f2, [:arglist]]]
  end

  parse <<-ruby do
      f1
      undef :x, :y, :z
    ruby

    [:block,
     [:call, nil, :f1, [:arglist]],
     [:undef, [:lit, :x]],
     [:undef, [:lit, :y]],
     [:undef, [:lit, :z]]]
  end

  parse <<-ruby do
      f1
      undef :x, :y, :z
      f2
    ruby

    [:block,
     [:call, nil, :f1, [:arglist]],
     [:undef, [:lit, :x]],
     [:undef, [:lit, :y]],
     [:undef, [:lit, :z]],
     [:call, nil, :f2, [:arglist]]]
  end

  parse "class B; undef :blah; end" do
    [:class, :B, nil, [:scope, [:block, [:undef, [:lit, :blah]]]]]
  end

  parse <<-ruby do
      undef :"x\#{1}", :"x\#{2}"
    ruby

    [:block,
      [:undef, [:dsym, "x", [:evstr, [:lit, 1]]]],
      [:undef, [:dsym, "x", [:evstr, [:lit, 2]]]]]
  end
end
