#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Testing solve function"){
  CHECK(solve("ymdk tmp m xuffxq xmyn") == "mary had a little lamb");

  CHECK(solve("nk qnkj bjwj uwjinhyfgqj ny btzqi hjfxj yt gj qnkj, fsi gj bnymtzy kqfatw") == "if life were predictable it would cease to be life, and be without flavor");

  CHECK(solve("kh aqw ugv aqwt iqcnu tkfkewnqwuna jkij cpf kv'u c hcknwtg, aqw yknn hckn cdqxg gxgtaqpg gnug'u uweeguu") == "if you set your goals ridiculously high and it's a failure, you will fail above everyone else's success");

  CHECK(solve("this is a test to see if it will encode when unnecessary") == "this is a test to see if it will encode when unnecessary");

  CHECK(solve("uxmmr ptl t vkxtmnkx hy atubm tgw lax mahnzam lax ebdxw bm matm ptr. matm ptl ngmbe wtox lahpxw ni bg axk ebyx. lax ghp atw t vahbvx mh ftdx tgw bm phnew wxmxkfbgx paxmaxk axk ebx kxftbgxw max ltfx hk by bm phnew vatgzx yhkxoxk.")
           == "betty was a creature of habit and she thought she liked it that way. that was until dave showed up in her life. she now had a choice to make and it would determine whether her lie remained the same or if it would change forever.");

}
