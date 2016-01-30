describe "An Ensure node" do
  parse <<-ruby do
      begin
        # do nothing
      rescue
        # do nothing
      ensure
        # do nothing
      end
    ruby

    [:ensure,
     [:rescue, [:nil], [:resbody, [:array, [:const, :StandardError]], [:nil]]],
     [:nil]]
  end

  parse <<-ruby do
      begin
        (1 + 1)
      rescue SyntaxError => e1
        2
      rescue Exception => e2
        3
      else
        4
      ensure
        5
      end
    ruby

    [:ensure,
     [:rescue,
      [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]],
      [:resbody,
       [:array, [:const, :SyntaxError], [:lasgn, :e1, [:gvar, :$!]]],
       [:lit, 2],
       [:resbody,
        [:array, [:const, :Exception], [:lasgn, :e2, [:gvar, :$!]]],
        [:lit, 3]]],
      [:lit, 4]],
     [:lit, 5]]
  end

  parse <<-ruby do
      begin
        a
      rescue
        # do nothing
      ensure
        # do nothing
      end
    ruby

    [:ensure,
     [:rescue,
      [:call, nil, :a, [:arglist]],
      [:resbody, [:array, [:const, :StandardError]], [:nil]]],
     [:nil]]
  end

  parse <<-ruby do
      begin
        a = 14
        return 2
      ensure
        13
      end
    ruby

    [:ensure, [:block, [:lasgn, :a, [:lit, 14]], [:return, [:lit, 2]]], [:lit, 13]]
  end

  parse <<-ruby do
      begin
        begin
          a = 14
          return 2
        ensure
          13
        end
      ensure
        15
      end
    ruby

    [:ensure,
     [:ensure,
      [:block, [:lasgn, :a, [:lit, 14]], [:return, [:lit, 2]]],
      [:lit, 13]],
     [:lit, 15]]
  end

  parse <<-ruby do
      begin
        a = 14
        return 2
      ensure
        begin
          b = 15
          return 3
        ensure
          16
        end
      end
    ruby

    [:ensure,
     [:block, [:lasgn, :a, [:lit, 14]], [:return, [:lit, 2]]],
     [:ensure,
      [:block, [:lasgn, :b, [:lit, 15]], [:return, [:lit, 3]]],
      [:lit, 16]]]
  end
end
