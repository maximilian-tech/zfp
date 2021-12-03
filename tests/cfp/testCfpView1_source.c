static void
_catFunc3(given_, CFP_VIEW_TYPE, _when_ctor_subset_expect_returnsNonNullPtr)(void **state)
{
  struct setupVars *bundle = *state;
  CFP_ARRAY_TYPE cfpArr = bundle->cfpArr;
  CFP_VIEW_TYPE cfpView = CFP_NAMESPACE.VIEW_NAMESPACE.ctor_subset(cfpArr, OFFSET_X, SIZE_X - OFFSET_X);
  
  assert_non_null(cfpView.object);
}

static void
_catFunc3(given_, CFP_VIEW_TYPE, _when_globalx_expect_offsetMatches)(void **state)
{
  struct setupVars *bundle = *state;
  CFP_ARRAY_TYPE cfpArr = bundle->cfpArr;
  CFP_VIEW_TYPE cfpView = bundle->cfpView;

  size_t offset = 1;

  assert_int_equal(CFP_NAMESPACE.VIEW_NAMESPACE.global_x(cfpView, offset), OFFSET_X+offset);
}

static void
_catFunc3(given_, CFP_VIEW_TYPE, _when_sizex_expect_sizeMatches)(void **state)
{
  struct setupVars *bundle = *state;
  CFP_ARRAY_TYPE cfpArr = bundle->cfpArr;
  CFP_VIEW_TYPE cfpView = bundle->cfpView;

  assert_int_equal(CFP_NAMESPACE.VIEW_NAMESPACE.size_x(cfpView), CFP_NAMESPACE.SUB_NAMESPACE.size_x(cfpArr));
}

static void
_catFunc3(given_, CFP_VIEW_TYPE, _when_set_expect_getValueMatches)(void **state)
{
  struct setupVars *bundle = *state;
  CFP_VIEW_TYPE cfpView = bundle->cfpView;

  SCALAR val = 3.5;
  size_t i = 1;

  CFP_NAMESPACE.VIEW_NAMESPACE.set(cfpView, i, val);
  assert_true(CFP_NAMESPACE.VIEW_NAMESPACE.get(cfpView, i) == val);
}