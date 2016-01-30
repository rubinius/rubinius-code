describe "A Flip2 node" do
  parse <<-ruby do
      x = if ((i % 4) == 0)..((i % 3) == 0)
        i
      else
        nil
      end
    ruby

    [:lasgn,
     :x,
     [:if,
      [:flip2,
       [:call,
        [:call, [:call, nil, :i, [:arglist]], :%, [:arglist, [:lit, 4]]],
        :==,
        [:arglist, [:lit, 0]]],
       [:call,
        [:call, [:call, nil, :i, [:arglist]], :%, [:arglist, [:lit, 3]]],
        :==,
        [:arglist, [:lit, 0]]]],
      [:call, nil, :i, [:arglist]],
      nil]]
  end

  parse <<-ruby do
      if 1..2.a?(b)
        nil
      end
    ruby

    [:if,
     [:flip2,
      [:lit, 1],
      [:call, [:lit, 2], :a?, [:arglist, [:call, nil, :b, [:arglist]]]]],
     [:nil],
     nil]
  end

  parse <<-ruby do
      x, y = 1, 2
      if x..y.a?(b)
        nil
      end
    ruby

    [:block,
     [:masgn,
      [:array, [:lasgn, :x], [:lasgn, :y]],
      [:array, [:lit, 1], [:lit, 2]]],
     [:if,
      [:flip2,
       [:lvar, :x],
       [:call, [:lvar, :y], :a?, [:arglist, [:call, nil, :b, [:arglist]]]]],
      [:nil],
      nil]]
  end

  parse <<-ruby do
      if x..y.a?(b)
        nil
      end
    ruby

    [:if,
     [:flip2,
      [:call, nil, :x, [:arglist]],
      [:call,
       [:call, nil, :y, [:arglist]],
       :a?,
       [:arglist, [:call, nil, :b, [:arglist]]]]],
     [:nil],
     nil]
  end
end
