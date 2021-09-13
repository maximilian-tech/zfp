static size_t
_t1(CFP_CONTAINER_TYPE, size_x)(const CFP_CONTAINER_TYPE self)
{
  return static_cast<const ZFP_CONTAINER_TYPE*>(self.object)->size_x();
}

static ZFP_SCALAR_TYPE
_t1(CFP_CONTAINER_TYPE, get)(const CFP_CONTAINER_TYPE self, size_t i)
{
  return static_cast<const ZFP_CONTAINER_TYPE*>(self.object)->operator()(i);
}

static void
_t1(CFP_CONTAINER_TYPE, set)(CFP_CONTAINER_TYPE self, size_t i, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_CONTAINER_TYPE*>(self.object)->operator()(i) = val;
}

/* References */

static CFP_REF_TYPE
_t1(CFP_CONTAINER_TYPE, ref)(CFP_CONTAINER_TYPE self, size_t i)
{
  CFP_REF_TYPE r;
  r.container = self.object;
  r.x = i;
  return r;
}

static ZFP_SCALAR_TYPE
_t2(CFP_CONTAINER_TYPE, CFP_REF_TYPE, get)(CFP_REF_TYPE self)
{
  return static_cast<const ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x);
}

static void
_t2(CFP_CONTAINER_TYPE, CFP_REF_TYPE, set)(CFP_REF_TYPE self, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x) = val;
}

static void
_t2(CFP_CONTAINER_TYPE, CFP_REF_TYPE, copy)(CFP_REF_TYPE self, CFP_REF_TYPE src)
{
  static_cast<ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x) =
    static_cast<const ZFP_CONTAINER_TYPE*>(src.container)->operator()(src.x);
}

/* Pointers */

static CFP_PTR_TYPE
_t1(CFP_CONTAINER_TYPE, ptr)(CFP_CONTAINER_TYPE self, size_t i)
{
  CFP_PTR_TYPE p;
  p.reference = _t1(CFP_CONTAINER_TYPE, ref)(self, i);
  return p;
}

/* Iterators */
static CFP_ITER_TYPE
_t1(CFP_CONTAINER_TYPE, begin)(CFP_CONTAINER_TYPE self)
{
  CFP_ITER_TYPE it;
  it.container = self.object;
  it.x = 0;
  return it;
}

static CFP_ITER_TYPE
_t1(CFP_CONTAINER_TYPE, end)(CFP_CONTAINER_TYPE self)
{
  CFP_ITER_TYPE it;
  it.container = self.object;
  it.x = static_cast<const ZFP_CONTAINER_TYPE*>(self.object)->size_x();
  return it;
}

static zfp_bool
_t1(CFP_ITER_TYPE, lt)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return lhs.container == rhs.container && lhs.x < rhs.x;
}

static zfp_bool
_t1(CFP_ITER_TYPE, gt)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return lhs.container == rhs.container && lhs.x > rhs.x;
}

static zfp_bool
_t1(CFP_ITER_TYPE, leq)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return lhs.container == rhs.container && lhs.x <= rhs.x;
}

static zfp_bool
_t1(CFP_ITER_TYPE, geq)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return lhs.container == rhs.container && lhs.x >= rhs.x;
}

static zfp_bool
_t1(CFP_ITER_TYPE, eq)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return lhs.container == rhs.container && lhs.x == rhs.x;
}

static zfp_bool
_t1(CFP_ITER_TYPE, neq)(CFP_ITER_TYPE lhs, CFP_ITER_TYPE rhs)
{
  return !_t1(CFP_ITER_TYPE, eq)(lhs, rhs);
}

static ptrdiff_t
_t1(CFP_ITER_TYPE, distance)(CFP_ITER_TYPE first, CFP_ITER_TYPE last)
{
   return last.x - first.x;
}

static CFP_ITER_TYPE
_t1(CFP_ITER_TYPE, next)(CFP_ITER_TYPE it, ptrdiff_t d)
{
  it.x += d;
  return it;
}

static CFP_ITER_TYPE
_t1(CFP_ITER_TYPE, prev)(CFP_ITER_TYPE it, ptrdiff_t d)
{
  it.x -= d;
  return it;
}

static CFP_ITER_TYPE
_t1(CFP_ITER_TYPE, inc)(CFP_ITER_TYPE it)
{
  it.x++;
  return it;
}

static CFP_ITER_TYPE
_t1(CFP_ITER_TYPE, dec)(CFP_ITER_TYPE it)
{
  it.x--;
  return it;
}

static ZFP_SCALAR_TYPE
_t1(CFP_ITER_TYPE, get)(CFP_ITER_TYPE self)
{
  return static_cast<const ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x);
}

static ZFP_SCALAR_TYPE
_t1(CFP_ITER_TYPE, get_at)(CFP_ITER_TYPE self, ptrdiff_t d)
{
  self = _t1(CFP_ITER_TYPE, next)(self, d);
  return static_cast<const ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x);
}

static void
_t1(CFP_ITER_TYPE, set)(CFP_ITER_TYPE self, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x) = val;
}

static void
_t1(CFP_ITER_TYPE, set_at)(CFP_ITER_TYPE self, ptrdiff_t d, ZFP_SCALAR_TYPE val)
{
  self = _t1(CFP_ITER_TYPE, next)(self, d);
  static_cast<ZFP_CONTAINER_TYPE*>(self.container)->operator()(self.x) = val;
}

static CFP_REF_TYPE
_t1(CFP_ITER_TYPE, ref)(CFP_ITER_TYPE self)
{
  CFP_CONTAINER_TYPE a;
  a.object = self.container;
  return _t1(CFP_CONTAINER_TYPE, ref)(a, self.x);
}

static CFP_REF_TYPE
_t1(CFP_ITER_TYPE, ref_at)(CFP_ITER_TYPE self, ptrdiff_t d)
{
  self = _t1(CFP_ITER_TYPE, next)(self, d);
  CFP_CONTAINER_TYPE a;
  a.object = self.container;
  return _t1(CFP_CONTAINER_TYPE, ref)(a, self.x);
}

static CFP_PTR_TYPE
_t1(CFP_ITER_TYPE, ptr)(CFP_ITER_TYPE self)
{
  CFP_CONTAINER_TYPE a;
  a.object = self.container;
  return _t1(CFP_CONTAINER_TYPE, ptr)(a, self.x);
}

static CFP_PTR_TYPE
_t1(CFP_ITER_TYPE, ptr_at)(CFP_ITER_TYPE self, ptrdiff_t d)
{
  self = _t1(CFP_ITER_TYPE, next)(self, d);
  CFP_CONTAINER_TYPE a;
  a.object = self.container;
  return _t1(CFP_CONTAINER_TYPE, ptr)(a, self.x);
}

static size_t
_t1(CFP_ITER_TYPE, i)(CFP_ITER_TYPE self)
{
  return self.x;
}
