describe "A While node" do
  pre_while_sexp = [
    :while,
     [:call, nil, :a, [:arglist]],
     [:call, [:call, nil, :b, [:arglist]], :+, [:arglist, [:lit, 1]]],
     true
  ]

  parse <<-ruby do
      while a
        b + 1
      end
    ruby

    pre_while_sexp
  end

  parse <<-ruby do
      a = x
      while a.b
        1
      end
    ruby

    [:block,
     [:lasgn, :a, [:call, nil, :x, [:arglist]]],
     [:while, [:call, [:lvar, :a], :b, [:arglist]], [:lit, 1], true]]
  end

  parse "b + 1 while a" do
    pre_while_sexp
  end

  parse <<-ruby do
      begin
        b + 1
      end while a
    ruby

    [:while,
     [:call, nil, :a, [:arglist]],
     [:call, [:call, nil, :b, [:arglist]], :+, [:arglist, [:lit, 1]]],
     false]
  end

  nil_condition_sexp = [:while, [:nil], [:call, nil, :a, [:arglist]], true]

  parse "a while ()" do
    nil_condition_sexp
  end

  parse <<-ruby do
      while ()
        a
      end
    ruby

    nil_condition_sexp
  end

  parse <<-ruby do
      while 1
        a = 2
        break :brk
      end
    ruby

    [:while,
     [:lit, 1],
     [:block, [:lasgn, :a, [:lit, 2]], [:break, [:lit, :brk]]],
     true]
  end

  parse <<-ruby do
      while 1
        begin
          a = 2
          break :brk
        rescue
          3
        end
      end
    ruby

    [:while,
     [:lit, 1],
     [:rescue,
      [:block, [:lasgn, :a, [:lit, 2]], [:break, [:lit, :brk]]],
      [:resbody, [:array, [:const, :StandardError]], [:lit, 3]]],
     true]
  end

  parse <<-ruby do
      while 1
        begin
          2
        rescue
          a = 3
          break :brk
        end
      end
    ruby

    [:while,
     [:lit, 1],
     [:rescue,
      [:lit, 2],
      [:resbody,
       [:array, [:const, :StandardError]],
       [[:lasgn, :a ,[:lit, 3]], [:break, [:lit, :brk]]]]],
     true]
  end
end
