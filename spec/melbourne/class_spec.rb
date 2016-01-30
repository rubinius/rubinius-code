describe "A Class node" do
  parse <<-ruby do
      class X
        puts((1 + 1))
        def blah
          puts("hello")
        end
      end
    ruby

    [:class,
     :X,
     nil,
     [:scope,
      [:block,
       [:call,
        nil,
        :puts,
        [:arglist, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]]],
       [:defn,
        :blah,
        [:args],
        [:scope,
         [:block, [:call, nil, :puts, [:arglist, [:str, "hello"]]]]]]]]]
  end

  parse <<-ruby do
      class ::Y
        c
      end
    ruby

    [:class, [:colon3, :Y], nil, [:scope, [:block, [:call, nil, :c, [:arglist]]]]]
  end

  parse <<-ruby do
      class X::Y
        c
      end
    ruby

    [:class,
     [:colon2, [:const, :X], :Y],
     nil,
     [:scope, [:block, [:call, nil, :c, [:arglist]]]]]
  end

  parse <<-ruby do
      class X < Array
      end
    ruby

    [:class, :X, [:const, :Array], [:scope]]
  end

  parse <<-ruby do
      class X < expr
      end
    ruby

    [:class, :X, [:call, nil, :expr, [:arglist]], [:scope]]
  end

  parse <<-ruby do
      class X < Object
      end
    ruby

    [:class, :X, [:const, :Object], [:scope]]
  end
end
