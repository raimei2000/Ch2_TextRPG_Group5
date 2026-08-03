#include "prologue.h"
#include "page_utils.h"

#include <iostream>
#include <string>
#include <cstdlib>

void PrintPrologue(const std::string& player_name) {
  std::cout << std::endl;
  std::cout << "========================================" << std::endl;
  std::cout << "          제13 던전 입장 안내" << std::endl;
  std::cout << "========================================" << std::endl;
  std::cout << std::endl;

  std::cout << "당신, " << player_name << "은(는) 오늘 처음 모험가 등록을 마친" << std::endl;
  std::cout << "초보 모험가입니다." << std::endl;
  std::cout << "당신은 의뢰 게시판에서" << std::endl;
  std::cout << "눈에 띄는 게시판을 보게 됩니다." << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "✨♚♚제13 던전 초보자 환영 파티♚♚✨" << std::endl;
  std::cout << "가입즉시$$신규모험가☜☜낡은검100%증정※" << std::endl;
  std::cout << "♜경력무관♜레벨무관♜생존경험무관￥" << std::endl;
  std::cout << "§§몬스터처치§§골드획득★★희귀아이템30%기회@@@" << std::endl;
  std::cout << "믿음직한동료♬안전한모험♬화려한보상♬" << std::endl;
  std::cout << "보스만잡으면즉시퇴장가능☞☞지금바로참가!!!" << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "※동료의 생존 여부는 당사가 책임지지 않습니다." << std::endl;
  std::cout << "※아이템 획득 확률은 모험가의 체감과 다를 수 있습니다." << std::endl;
  std::cout << std::endl;

  std::cout << player_name << "은(는) 화려하게 번쩍이는 문구에 정신이 팔린 나머지," << std::endl;
  std::cout << "아래에 작게 적힌 주의사항을 읽지 못했습니다." << std::endl;
  std::cout << "그리고 등록한 지 10분 만에," << std::endl;
  std::cout << "보스 토벌 파티의 마지막 자리에" << std::endl;
  std::cout << "강제로 배정되었습니다." << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "\"✨♚♚제13 던전 초보자 환영 파티♚♚✨\"라는 설명과 달리" << std::endl;
  std::cout << "당신을 기다리고 있던 것은 음산한 던전과" << std::endl;
  std::cout << "조금도 환영할 생각이 없어 보이는" << std::endl;
  std::cout << "몬스터들이었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "던전에 들어선 지 얼마 지나지 않아" << std::endl;
  std::cout << "정체불명의 몬스터들이 파티를 습격했습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "비명과 고함이 뒤섞였고," << std::endl;
  std::cout << "당신은 강한 충격과 함께 정신을 잃었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "정신을 차렸을 때," << std::endl;
  std::cout << "당신과 함께 싸울 수 있는 동료는" << std::endl;
  std::cout << "아무도 남아 있지 않았습니다." << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "전투의 흔적이 가득한 방 한가운데에서는" << std::endl;
  std::cout << "술 취한 오크 한 마리가 동료의 투구에" << std::endl;
  std::cout << "술을 따라 마시며 혼자 낄낄거리고 있었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "\"인간들 장비는 약해도" << std::endl;
  std::cout << "술잔으로는 쓸 만하군!\"" << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "방구석에는 거대한 트롤이 웅크리고 앉아" << std::endl;
  std::cout << "무언가를 정신없이 씹고 있었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "트롤은 당신과 눈이 마주치자" << std::endl;
  std::cout << "움직임을 멈추고 낮게 중얼거렸습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "\"단백질...... 더 필요해......\"" << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "그 옆에서는 악취 고블린들이" << std::endl;
  std::cout << "쓰러진 동료들의 가방을 뒤지고 있었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "\"반짝이는 건 내 거다!\"" << std::endl;
  std::cout << "\"먹을 수 있는 것도 내 거다!\"" << std::endl;
  std::cout << "\"냄새나는 건...... 난 아니야!!\"" << std::endl;
  std::cout << std::endl;

  std::cout << "당신은 숨을 죽인 채" << std::endl;
  std::cout << "천천히 낡은 검을 움켜쥐었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "두려움 때문인지," << std::endl;
  std::cout << "지독한 고블린 냄새 때문인지는 알 수 없었지만" << std::endl;
  std::cout << "눈에서는 계속 눈물이 흘렀습니다." << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "그 순간," << std::endl;
  std::cout << "던전 전체에 상황과 전혀 어울리지 않는" << std::endl;
  std::cout << "밝고 경쾌한 목소리가 울려 퍼졌습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "[던전 관리 시스템]" << std::endl;
  std::cout << std::endl;

  std::cout << "\"파티원 전원의 전투 불능을 확인했습니다.\"" << std::endl;
  std::cout << std::endl;

  std::cout << "\"생존자 1명을 임시 파티장으로 승격합니다.\"" << std::endl;
  std::cout << std::endl;

  std::cout << "\"축하합니다, " << player_name << " 님!\"" << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "축하할 상황은 전혀 아니었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "다행히 던전 관리 시스템은" << std::endl;
  std::cout << "각 구역 사이에 안전지대를 운영하고 있었습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "안전지대에서는 현재 상태를 확인하거나," << std::endl;
  std::cout << "몬스터에게서 획득한 골드로" << std::endl;
  std::cout << "무인 상점을 이용할 수 있습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "하지만 당신이 들어온 던전의 문은" << std::endl;
  std::cout << "어느새 흔적도 없이 사라져 있었습니다." << std::endl;
  std::cout << std::endl;

  if ( EnterToNextPage("프롤로그") ) {
    return;
  }

  std::cout << "[던전 관리 시스템]" << std::endl;
  std::cout << std::endl;

  std::cout << "\"퇴장을 원하신다면" << std::endl;
  std::cout << "최하층의 보스를 처치하세요.\"" << std::endl;
  std::cout << std::endl;

  std::cout << "\"참고로 중도 포기와 환불은 불가능합니다.\"" << std::endl;
  std::cout << std::endl;

  std::cout << "당신은 낡은 무기를 고쳐 잡았습니다." << std::endl;
  std::cout << std::endl;

  std::cout << "살아남기 위해서," << std::endl;
  std::cout << "사라진 동료들의 복수를 위해서," << std::endl;
  std::cout << "그리고 이 엉망인 던전에서 퇴근하기 위해서." << std::endl;
  std::cout << std::endl;

  std::cout << "초보 모험가 " << player_name << "의" << std::endl;

  std::cout << "예정에 없던 단독 공략이 지금 시작됩니다." << std::endl;
  std::cout << std::endl;

  std::cout << "========================================" << std::endl;

  std::cout << "Enter 키를 눌러 게임을 진행합니다..";
  std::string input;
  std::getline(std::cin, input);

  std::cout << std::endl;
  std::cout << std::endl;
}