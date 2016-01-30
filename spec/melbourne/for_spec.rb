describe "A For node" do
  parse <<-ruby do
      for o in ary do
        puts(o)
      end
    ruby

    [:for,
     [:args, [:lasgn, :o]],
     [:call, nil, :ary, [:arglist]],
     [:call, nil, :puts, [:arglist, [:lvar, :o]]]]
  end

  parse <<-ruby do
      for i in (0..max) do
        # do nothing
      end
    ruby

    [:for,
     [:args, [:lasgn, :i]],
     [:dot2, [:lit, 0], [:call, nil, :max, [:arglist]]],
     [:nil]]
  end

  parse <<-ruby do
      for a, b in x do
        5
      end
    ruby

    [:for,
     [:args, [:masgn, [:array, [:lasgn, :a], [:lasgn, :b]]]],
     [:call, nil, :x, [:arglist]],
     [:lit, 5]]
  end

  parse <<-ruby do
      for i in ()
        i
      end
    ruby

    [:for, [:args, [:lasgn, :i]], [:nil], [:lvar, :i]]
  end

  parse <<-ruby do
      c = 1
      for i in a
        for j in b
          c
        end
      end
    ruby

    [:block,
     [:lasgn, :c, [:lit, 1]],
     [:for,
      [:args, [:lasgn, :i]],
      [:call, nil, :a, [:arglist]],
      [:for, [:args, [:lasgn, :j]], [:call, nil, :b, [:arglist]], [:lvar, :c]]]]
  end
end
