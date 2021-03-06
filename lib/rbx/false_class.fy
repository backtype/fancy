class FalseClass {
  """
  FalseClass extensions for Fancy on rbx.
  """

  def if_true: then_block else: else_block {
    "Calls else_block."
    else_block call
  }

  def if_true: block {
    "Returns nil."
    nil
  }

  def if_false: block {
    "Calls the block."
    block call
  }

  def if_nil: block {
    "Calls the block."
    nil
  }

  def nil? {
    "Returns true."
    false
  }

  def false? {
    "Returns true."
    true
  }

  def true? {
    "Returns nil."
    false
  }

  def to_s {
    "false"
  }

  def to_a {
    []
  }

  def not {
    """
    @return @true

    Boolean negation of @false => @true.
    """

    true
  }
}
