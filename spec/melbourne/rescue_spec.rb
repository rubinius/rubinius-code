describe "A Rescue node" do
  parse "blah rescue nil" do
    [:rescue,
     [:call, nil, :blah, [:arglist]],
     [:resbody, [:array, [:const, :StandardError]], [:nil]]]
  end

  parse <<-ruby do
      begin
        blah
      rescue
      end
    ruby

    [:rescue,
     [:call, nil, :blah, [:arglist]],
     [:resbody, [:array, [:const, :StandardError]], [:nil]]]
  end

  parse <<-ruby do
      begin
        a
      rescue A
        b
      rescue B
        c
      rescue C
        d
      end
    ruby

    [:rescue,
     [:call, nil, :a, [:arglist]],
     [:resbody,
      [:array, [:const, :A]],
      [:call, nil, :b, [:arglist]],
      [:resbody,
       [:array, [:const, :B]],
       [:call, nil, :c, [:arglist]],
       [:resbody, [:array, [:const, :C]], [:call, nil, :d, [:arglist]]]]]]
  end

  parse <<-ruby do
      begin
        a
      rescue => @e
        c
        d
      end
    ruby

    [:rescue,
     [:call, nil, :a, [:arglist]],
     [:resbody,
      [:array, [:const, :StandardError], [:iasgn, :@e, [:gvar, :$!]]],
      [[:call, nil, :c, [:arglist]], [:call, nil, :d, [:arglist]]]]]
  end

  parse <<-ruby do
      begin
        a
      rescue => e
        c
        d
      end
    ruby

    [:rescue,
     [:call, nil, :a, [:arglist]],
     [:resbody,
      [:array, [:const, :StandardError], [:lasgn, :e, [:gvar, :$!]]],
      [[:call, nil, :c, [:arglist]], [:call, nil, :d, [:arglist]]]]]
  end

  parse <<-ruby do
      begin
        a
      rescue => mes
        # do nothing
      end

      begin
        b
      rescue => mes
        # do nothing
      end
    ruby

    [:block,
     [:rescue,
      [:call, nil, :a, [:arglist]],
      [:resbody,
       [:array, [:const, :StandardError], [:lasgn, :mes, [:gvar, :$!]]],
       [:nil]]],
     [:rescue,
      [:call, nil, :b, [:arglist]],
      [:resbody,
       [:array, [:const, :StandardError], [:lasgn, :mes, [:gvar, :$!]]],
       [:nil]]]]
  end

  parse <<-ruby do
      begin
        blah
      rescue RuntimeError => r
      end
    ruby

    [:rescue,
     [:call, nil, :blah, [:arglist]],
     [:resbody,
      [:array, [:const, :RuntimeError], [:lasgn, :r, [:gvar, :$!]]],
      [:nil]]]
  end

  parse <<-ruby do
      begin
        1
      rescue => @e
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError], [:iasgn, :@e, [:gvar, :$!]]],
      [:nil]]]
  end

  parse <<-ruby do
      begin
        1
      rescue
        var = 2
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody, [:array, [:const, :StandardError]], [:lasgn, :var, [:lit, 2]]]]
  end

  parse <<-ruby do
      begin
        1
      rescue => e
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError], [:lasgn, :e, [:gvar, :$!]]],
      [:nil]]]
  end

  parse <<-ruby do
      begin
        1
      rescue
        a.b = nil
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError]],
      [:attrasgn, [:call, nil, :a, [:arglist]], :b=, [:arglist, [:nil]]]]]
  end

  parse <<-ruby do
      begin
        1
      rescue => e
        var = 2
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError], [:lasgn, :e, [:gvar, :$!]]],
      [:lasgn, :var, [:lit, 2]]]]
  end

  parse <<-ruby do
      begin
        12
      rescue String
        13
      else
        14
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody, [:array, [:const, :String]], [:lit, 13]],
     [:lit, 14]]
  end

  parse <<-ruby do
      begin
        12
      rescue *blah
        13
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody, [:splat, [:call, nil, :blah, [:arglist]]], [:lit, 13]]]
  end

  parse <<-ruby do
      begin
        12
      rescue String, *blah
        13
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody,
      [:array, [:const, :String], [:splat, [:call, nil, :blah, [:arglist]]]],
      [:lit, 13]]]
  end

  parse <<-ruby do
      begin
        12
      rescue *blah => e
        13
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody,
      [:splat, [:call, nil, :blah, [:arglist]]],
      [:lasgn, :e, [:gvar, :$!]],
      [:lit, 13]]]
  end

  parse <<-ruby do
      begin
        12
      rescue String, *blah => e
        13
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody,
      [:array,
       [:const, :String],
       [:splat, [:call, nil, :blah, [:arglist]]],
       [:lasgn, :e, [:gvar, :$!]]],
      [:lit, 13]]]
  end

  parse <<-ruby do
      begin
        12
      rescue String
        return nil
      end
    ruby

    [:rescue,
     [:lit, 12],
     [:resbody, [:array, [:const, :String]], [:return, [:nil]]]]
  end

  parse <<-ruby do
      begin
        1
      rescue
        begin
          2
        rescue
          return 3
        end
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError]],
      [:rescue,
       [:lit, 2],
       [:resbody, [:array, [:const, :StandardError]], [:return, [:lit, 3]]]]]]
  end

  parse <<-ruby do
      begin
        1
      rescue
        def x
          return 2
        end
        x
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError]],
      [[:defn, :x, [:args], [:scope, [:block, [:return, [:lit, 2]]]]],
       [:call, nil, :x, [:arglist]]]]]
  end

  parse <<-ruby do
      begin
        while 1
          a = 2
          break :brk
        end
      rescue
        3
      end
    ruby

    [:rescue,
     [:while,
      [:lit, 1],
      [:block, [:lasgn, :a, [:lit, 2]], [:break, [:lit, :brk]]],
      true],
     [:resbody, [:array, [:const, :StandardError]], [:lit, 3]]]
  end

  parse <<-ruby do
      begin
        1
      rescue
        while 2
          a = 3
          break :brk
        end
      end
    ruby

    [:rescue,
     [:lit, 1],
     [:resbody,
      [:array, [:const, :StandardError]],
      [:while,
       [:lit, 2],
       [:block, [:lasgn, :a, [:lit, 3]], [:break, [:lit, :brk]]],
       true]]]
  end
end
