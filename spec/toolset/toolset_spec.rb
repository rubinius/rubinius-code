describe "Rubinius::ToolSets.create" do
  before :each do
    module ::CodeTools
      ToolSetCodeTools = 1
    end
  end

  after :each do
    ::Object.send :remove_const, :CodeTools rescue nil
  end

  it "creates a new ToolSet" do
    m = Rubinius::ToolSets.current
    Rubinius::ToolSets.create.should_not equal(m)
  end

  it "accepts an optional name for the ToolSet" do
    ts = Rubinius::ToolSets.create :a_tool_set
    ts.name.should == "Rubinius::ToolSets::AToolSet"
  end

  it "sets .current to the ToolSet that is yielded to the block" do
    Rubinius::ToolSets.create do |ts|
      ts.should equal(Rubinius::ToolSets.current)
    end
  end

  it "resets $LOADED_FEATURES while running the block" do
    Rubinius::ToolSets.create do
      $LOADED_FEATURES.should == []
    end
  end

  it "restores the original set of $LOADED_FEATURES after running the block" do
    $LOADED_FEATURES.should_not be_empty
    previously_loaded_features = $LOADED_FEATURES.dup
    Rubinius::ToolSets.create do end
    $LOADED_FEATURES.should == previously_loaded_features
  end

  it "sets the 'ToolSet' constant on the yielded ToolSet to refer to itself" do
    Rubinius::ToolSets.create :spec do |ts|
      ts.should equal(ts::ToolSet)
    end
  end

  it "includes the ::CodeTools constant in the current ToolSet" do
    ts = Rubinius::ToolSets.create(:spec) { |ts| ts }
    ts.const_defined?(:ToolSetCodeTools).should be_true
  end

  it "removes the ::CodeTools constant after yielding" do
    Rubinius::ToolSets.create(:spec) { }
    Object.const_defined?(:ToolSetCodeTools).should be_false
  end
end

describe "Rubinius::ToolSets.current" do
  it "returns the ToolSet created by .create" do
    ts = Rubinius::ToolSets.create
    Rubinius::ToolSets.current.should equal(ts)
  end

  it "returns the same ToolSet on each call" do
    ts = Rubinius::ToolSets.current
    ts.should equal(Rubinius::ToolSets.current)
  end
end
