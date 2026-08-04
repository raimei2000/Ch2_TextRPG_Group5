#include "epilogue.h"
#include "page_utils.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

void ShowEpilogue(const std::string& player_name) {

	std::vector<std::string> epilogue_lines = {
		"========================================",
		"                EPILOGUE",
		"========================================",
		"",
		"마침내 꼰대 오우거의 거대한 몸을",
		"간신히 쓰러뜨렸습니다.",
		"",
	};

	EndingScroll(epilogue_lines);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines2 = {
		"쿵──!",
		"",
		"충격과 함께 던전 전체가 크게 흔들렸습니다.",
		"",
		"꼰대 오우거는 믿을 수 없다는 표정으로",
		"당신을 올려다보았습니다.",
		"",
		"[꼰대 오우거]",
		"\"요즘 모험가들은 말이야……\"",
		"\"내가 젊었을 때는 장비도 없이\"",
		"\"맨손으로 던전을 정복했어……\"",
		"\"자네도 조금만 더 노력하면……\"",
		"",
		"그 말을 끝으로 꼰대 오우거는 눈을 감았습니다.",
		"마지막 순간까지도 잔소리를 멈추지 않았습니다.",
	};
	EndingScroll(epilogue_lines2);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines3 = {
		"잠시 후, 던전 전체에 익숙한 목소리가",
		"울려 퍼졌습니다.",
		"",
		"[던전 관리 시스템]",
		"\"최하층 보스의 전투 불능을 확인했습니다.\"",
		"\"임시 파티장님의 던전 공략이 완료되었습니다.\"",
		"",
		"\"생존율을 계산합니다……\"",
		"\"파티원 한 명이 입장하여 한 명이 생존했으므로\"",
		"\"생존율은 100%로 처리하겠습니다.\"",
		"",
		"어딘가 이상한 계산이었지만,",
		"당신에게는 반박할 힘이 남아 있지 않았습니다.",
		"",
		"굳게 닫혀 있던 던전의 문이 천천히 열리고,",
		"오랜만에 보는 햇빛이 던전 안으로 들어왔습니다.",
	};

	EndingScroll(epilogue_lines3);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines4 = {
		"당신은 살아남았습니다.",
		"",
		"초보 모험가로 들어왔던 당신은",
		"이제 누구도 무시할 수 없는 모험가가 되었습니다.",
		"",
		"그러나 출구를 통과하려던 순간,",
		"던전 관리 시스템이 마지막 안내를 시작했습니다.",
		""
	};

	EndingScroll(epilogue_lines4);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines5 = {
		"[던전 관리 시스템]",
		"\"던전 시설 이용료를 정산합니다.\"",
		"\"몬스터 청소 비용, 안전지대 이용료,\"",
		"\"무인 상점 부가세가 포함됩니다.\"",
		"\"총 이용료는 보유 골드 전액입니다.\"",
		"",
		"당신의 주머니에서 던전에서 간신히 모아온 목숨같은 전재산이 사라졌습니다.",
		"",
		"[던전 관리 시스템]",
		"\"정상적으로 결제되었습니다.\"",
		"\"다음 방문을 기대하겠습니다.\""
	};

	EndingScroll(epilogue_lines5);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines6 = {
		"당신은 아무 말 없이 출구를 걸어 나갔습니다.",
		"다시는 이곳에 돌아오지 않겠다고 다짐하면서.",
		"",
		"하지만 얼마뒤 의뢰 게시판에는",
		"새로운 모집 공고가 붙어 있었습니다.",
		""
	};

	EndingScroll(epilogue_lines6);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}
	std::vector<std::string> epilogue_lines7 = {

	 "             +({xi ",
	 "             >?[)/}                                       ,+]/t|1!  ",
	 "             i-]{(]                                       l!? / fj]<                         ",
	 "        >[1tf|1tffjvccrnxtnucUr|J0QQUCzYXvufvXXnvUCQJQJXurczftzxcnxzXn]'                    ",
	 "        :<>+]>;<i+}{-|rrjjr/ftrux))|rxnurjunvucn(|unjj|}(j[i->|tfggsyft{+                    ",
	 "       ;;;;l``.`^;!'':::II; ,',:Illl; l!i!iIl; I!i!!!i!;; II;; I;;II; ^:;l'                    ",
	 "            ,<>|                                                {{>l'",
	 "            I]1[   ========================================     t(+'l                      ",
	 "            >-1]      ✨♚♚제14 던전 초보자 환영 파티♚♚✨        xz1",
	 "            l?(]      가입즉시$$신규모험가☜☜낡은검100% 증정     1//?  ",
	 "            >}t(       ♜경력무관♜레벨무관♜생존경험무관￥        cc/>",
	 "            <}[?  §§몬스터처치§§골드획득★★희귀아이템30 % 기회@@ tfx~",
	 "            +1]+      믿음직한동료♬안전한모험♬화려한보상♬       rt)1",
	 "            :~((     보스만잡으면즉시퇴장가능☞☞지금바로참가!!!  /t[",
	 "            i-([   ========================================     |_l",
	 "            i}/?                                                (/)}  ",
	 "            l[|]{nnLvYY0JcLpkkbdqpbkdpdddbbdqkhoppZpwpZmwOLCjfxdwjj( ",
	 "            `l_-1_v}|fuX00zCLZmwYZmqdqqdbkkkbahk0UpqZXcYXfzcreds})/}",
	 "            l]]]u},[/)uxxuvr{jfcLvLCQO0ZQJZpJfzzYC0CLzcJUu!zfadxf1){_",
	 "           l!<<+!il_]i][}}-1(jtft(1]+__1)(/|()ttt|rjx|[?1-1>-ffffff[i ",
	 "             `'^^;:,^ ;'';,' ^ '      .^.  ';^   ,^`''^I;``^''   ",
	 "              :l~[/?i :,                                ,l+~|+i^  ",
	 "              !<_]|/-!                                  ll?)j}< ",
	 "              l<+}|]_i                                  !i/fx(+ ",
	 "              l_<{f(1!                                  i?tfj/]   ",
	 "              l+?{r/{I                                  '<-? (rx",
	 "              ;!+((j]!                                  `!!{{[|[+ ",
	 "              +I+}|1{!                                  I+(|}f~   ",
	 "              ;!<-}-1!                                  ;+{}t1_  ",
	 "              :i+}[{}<                                   -_{<)_",
	 "               I<1-                                       +]     ",



	};

	ShowAllAtOnce(epilogue_lines7);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines8 = {
		"당신은 조용히 모집 공고를 찢어버렸습니다.",
		"",
		"그렇게 " + player_name + "의",
		"예정에 없던 단독 던전 공략은 끝이 났습니다.",
		"",
		"========================================",
		"            THE HAPPY END?",
		"========================================"
	};

	EndingScroll(epilogue_lines8);

	if ( EnterToNextPage("에필로그") ) {
		return;
	}

	std::vector<std::string> epilogue_lines9 = {

	 "             +({xi ",
	 "             >?[)/}                                       ,+]/t|1!  ",
	 "             i-]{(]                                       l!? / fj]<                         ",
	 "        >[1tf|1tffjvccrnxtnucUr|J0QQUCzYXvufvXXnvUCQJQJXurczftzxcnxzXn]'                    ",
	 "        :<>+]>;<i+}{-|rrjjr/ftrux))|rxnurjunvucn(|unjj|}(j[i->|tfggsyft{+                    ",
	 "       ;;;;l``.`^;!'':::II; ,',:Illl; l!i!iIl; I!i!!!i!;; II;; I;;II; ^:;l'                    ",
	 "            ,<>|                                                {{>l'",
	 "            I]1[   ========                             ===     t(+'l                      ",
	 "            >-1]      ✨♚                            ♚✨        xz1",
	 "            l?(]      가입                             증정     1//?  ",
	 "            >}t(       ♜           무               ￥          cc/>",
	 "            <}[?  §§몬스           획득             0 % 기회@@  tfx~",
	 "            +1]+      믿          안전             상♬          rt)1",
	 "            :~((     보          시퇴장            로참가!!!    /t[",
	 "            i-([   ===          ======            =========     |_l",
	 "            i}/?                                                (/)}  ",
	 "            l[|]{nnLvYY0JcLpkkbdqpbkdpdddbbdqkhoppZpwpZmwOLCjfxdwjj( ",
	 "            `l_-1_v}|fuX00zCLZmwYZmqdqqdbkkkbahk0UpqZXcYXfzcreds})/}",
	 "            l]]]u},[/)uxxuvr{jfcLvLCQO0ZQJZpJfzzYC0CLzcJUu!zfadxf1){_",
	 "           l!<<+!il_]i][}}-1(jtft(1]+__1)(/|()ttt|rjx|[?1-1>-ffffff[i ",
	 "             `'^^;:,^ ;'';,' ^ '      .^.  ';^   ,^`''^I;``^''   ",
	 "              :l~[/?i :,                                ,l+~|+i^  ",
	 "              !<_]|/-!                                  ll?)j}< ",
	 "              l<+}|]_i                                  !i/fx(+ ",
	 "              l_<{f(1!                                  i?tfj/]   ",
	 "              l+?{r/{I                                  '<-? (rx",
	 "              ;!+((j]!                                  `!!{{[|[+ ",
	 "              +I+}|1{!                                  I+(|}f~   ",
	 "              ;!<-}-1!                                  ;+{}t1_  ",
	 "              :i+}[{}<                                   -_{<)_",
	 "               I<1-                                       +]     ",



	};

	DelayShowAllAtOnce(epilogue_lines9);

	std::vector<std::string> epilogue_lines10 = {

	 "             +({xi ",
	 "             >?[)/}                                       ,+]/t|1!  ",
	 "             i-]{(]                                       l!? / fj]<                         ",
	 "        >[1tf|1tffjvccrnxtnucUr|J0QQUCzYXvufvXXnvUCQJQJXurczftzxcnxzXn]'                    ",
	 "        :<>+]>;<i+}{-|rrjjr/ftrux))|rxnurjunvucn(|unjj|}(j[i->|tfggsyft{+                    ",
	 "       ;;;;l``.`^;!'':::II; ,',:Illl; l!i!iIl; I!i!!!i!;; II;; I;;II; ^:;l'                    ",
	 "            ,<>|                                                {{>l'",
	 "            I]1[   ========================================     t(+'l                      ",
	 "            >-1]      ✨♚♚제14 던전 초보자 환영 파티♚♚✨        xz1",
	 "            l?(]      가입즉시$$신규모험가☜☜낡은검100% 증정     1//?  ",
	 "            >}t(       ♜경력무관♜레벨무관♜생존경험무관￥        cc/>",
	 "            <}[?  §§몬스터처치§§골드획득★★희귀아이템30 % 기회@@ tfx~",
	 "            +1]+      믿음직한동료♬안전한모험♬화려한보상♬       rt)1",
	 "            :~((     보스만잡으면즉시퇴장가능☞☞지금바로참가!!!  /t[",
	 "            i-([   ========================================     |_l",
	 "            i}/?                                                (/)}  ",
	 "            l[|]{nnLvYY0JcLpkkbdqpbkdpdddbbdqkhoppZpwpZmwOLCjfxdwjj( ",
	 "            `l_-1_v}|fuX00zCLZmwYZmqdqqdbkkkbahk0UpqZXcYXfzcreds})/}",
	 "            l]]]u},[/)uxxuvr{jfcLvLCQO0ZQJZpJfzzYC0CLzcJUu!zfadxf1){_",
	 "           l!<<+!il_]i][}}-1(jtft(1]+__1)(/|()ttt|rjx|[?1-1>-ffffff[i ",
	 "             `'^^;:,^ ;'';,' ^ '      .^.  ';^   ,^`''^I;``^''   ",
	 "              :l~[/?i :,                                ,l+~|+i^  ",
	 "              !<_]|/-!                                  ll?)j}< ",
	 "              l<+}|]_i                                  !i/fx(+ ",
	 "              l_<{f(1!                                  i?tfj/]   ",
	 "              l+?{r/{I                                  '<-? (rx",
	 "              ;!+((j]!                                  `!!{{[|[+ ",
	 "              +I+}|1{!                                  I+(|}f~   ",
	 "              ;!<-}-1!                                  ;+{}t1_  ",
	 "              :i+}[{}<                                   -_{<)_",
	 "               I<1-                                       +]     ",
	 ""



	};

	ShowAllAtOnce(epilogue_lines10);
}