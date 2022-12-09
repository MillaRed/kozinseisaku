#include "AnimData.h"


static TexAnim playerIdle[] = {
	{ 19,5 },
	{ 18,5 },
	{ 17,5 },
	{ 16,5 },
};
static TexAnim playerRun[] = {
	{ 114,3 },
	{ 113,3 },
	{ 112,3 },
	{ 111,5 },
};
static TexAnim playerJumpUp[] = {
	{ 114,3 },
	{ 113,3 },
	{ 112,3 },
	{ 111,3 },
};
static TexAnim playerJumpDown[] = {
	{ 114,3 },
	{ 113,3 },
	{ 112,3 },
	{ 111,3 },
};
static TexAnim playerAttack01[] = {
	{ 14,3 },
	{ 13,3 },
	{ 12,3 },
	{ 11,5 },
};
static TexAnim playerAttack01End[] = {
	{ 0,0 },
};
static TexAnim playerAttack02[] = {
	{ 34,6 },
	{ 33,6 },
	{ 32,4 },
	{ 31,2 },
};
static TexAnim playerAttack02End[] = {
	{ 0,0 },
};
static TexAnim playerAttack03[] = {
	{ 54,6 },
	{ 53,6 },
	{ 52,4 },
	{ 51,4 },
};
static TexAnim playerAttack03End[] = {
	{ 0,0 },
}; 

static TexAnim playerDamage[] = {
	{ 99,2 },
	{ 98,2 },
	{ 97,2 },
	{ 96,2 },
};
static TexAnim playerDamageEnd[] = {
	{ 0,0 },
};
static TexAnim playerDeath[] = {
	{ 24,4 },
	{ 23,4 },
	{ 22,4 },
	{ 21,4 },
	{ 109,4 },
	{ 108,4 },
	{ 107,4 },
	{ 106,4 },
};

static TexAnim playerDown[] = {
	{ 0,0 },
};
static TexAnim playerDownGround[] = {
	{ 0,0 },
};
static TexAnim playerWakeup[] = {
	{ 0,0 },
};
static TexAnim playerGuard[] = {
	{ 79,4 },
	{ 78,4 },
	{ 77,4 },
	{ 76,4 },
};
static TexAnim playerGuardEnd[] = {
	{ 0,0 },
};
static TexAnim playerCrash[] = {
	{ 0,0 },
};
static TexAnim playerCrash01End[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack01[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack01End[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack02[] = {
	{ 0,0 },
};
static TexAnim playerExtAttack02End[] = {
	{ 0,0 },

};
static TexAnim playerStep[] = {
	{ 0,0 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerDownGround),
	ANIMDATA(playerWakeup),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerCrash),
	ANIMDATA(playerCrash01End),
	ANIMDATA(playerExtAttack01),
	ANIMDATA(playerExtAttack01End),
	ANIMDATA(playerExtAttack02),
	ANIMDATA(playerExtAttack02End),
	ANIMDATA(playerStep),
};

static TexAnim enemyIdle[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
};
static TexAnim enemyRun[] = {
	{ 105,2 },
	{ 106,2 },
	{ 107,2 },
	{ 108,2 },
};
static TexAnim enemyJumpUp[] = {
	{ 0,0 },
};
static TexAnim enemyJumpDown[] = {
	{ 0,0 },
};

static TexAnim enemyAttack01[] = {
	{ 5,4 },
	{ 6,4 },
	{ 7,4 },
	{ 8,8 },
};
static TexAnim enemyAttack01End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03End[] = {
	{ 0,0 },
};
static TexAnim enemyDamage[] = {
	{ 80,2 },
	{ 81,2 },
	{ 82,2 },
	{ 83,2 },
};
static TexAnim enemyDamageEnd[] = {
	{ 0,0 },
};
static TexAnim enemyDeath[] = {
	{ 80,2 },
};

static TexAnim enemyDown[] = {
	{ 0,0 },
};
static TexAnim enemyDownGround[] = {
	{ 0,0 },
};
static TexAnim enemyWakeup[] = {
	{ 0,0 },
};
static TexAnim enemyGuard[] = {
	{ 0,0 },
};
static TexAnim enemyGuardEnd[] = {
	{ 0,0 },
};
static TexAnim enemyCrash[] = {
	{ 0,0 },
};
static TexAnim enemyCrash01End[] = {
	{ 0,0 },
};
static TexAnim enemyExt01Attack[] = {
	{ 0,0 },
};
static TexAnim enemyExtAttack01End[] = {
	{ 0,0 },
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyRun),
	ANIMDATA(enemyJumpUp),
	ANIMDATA(enemyJumpDown),
	ANIMDATA(enemyAttack01),
	ANIMDATA(enemyAttack01End),
	ANIMDATA(enemyAttack02),
	ANIMDATA(enemyAttack02End),
	ANIMDATA(enemyAttack03),
	ANIMDATA(enemyAttack03End),
	ANIMDATA(enemyDamage),
	ANIMDATA(enemyDamageEnd),
	ANIMDATA(enemyDeath),
	ANIMDATA(enemyDown),
	ANIMDATA(enemyDownGround),
	ANIMDATA(enemyWakeup),
	ANIMDATA(enemyGuard),
	ANIMDATA(enemyGuardEnd),
	ANIMDATA(enemyCrash),
	ANIMDATA(enemyCrash01End),
	ANIMDATA(enemyExt01Attack),
	ANIMDATA(enemyExtAttack01End),
};

static TexAnim bossIdle[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
};
static TexAnim bossRun[] = {
	{ 40,2 },
	{ 41,2 },
	{ 42,2 },
	{ 43,2 },
};
static TexAnim bossJumpUp[] = {
	{ 10,0 },
	{ 11,0 },
	{ 12,0 },
	{ 13,0 },
};
static TexAnim bossJumpDown[] = {
	{ 0,0 },
};
static TexAnim bossAttack01[] = {
	{ 5,0 },
	{ 6,0 },
	{ 7,0 },
	{ 8,0 },
};
static TexAnim bossAttack01End[] = {
	{ 0,0 },
};
static TexAnim bossDamage[] = {
	{ 80,0 },
	{ 81,0 },
	{ 82,0 },
	{ 83,0 },
};
static TexAnim bossDamageEnd[] = {
	{ 0,0 },
};
static TexAnim bossDeath[] = {
	{ 0,0 },
};
TexAnimData boss_anim_data[] = {
	ANIMDATA(bossIdle),
	ANIMDATA(bossRun),
	ANIMDATA(bossJumpUp),
	ANIMDATA(bossJumpDown),
	ANIMDATA(bossAttack01),
	ANIMDATA(bossAttack01End),
	ANIMDATA(bossDamage),
	ANIMDATA(bossDamageEnd),
	ANIMDATA(bossDeath),
};


static TexAnim _effect_blood[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
};
TexAnimData effect_blood_anim_data[] = {
	ANIMDATA(_effect_blood),
};
static TexAnim _effect_smoke[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_smoke_anim_data[] = {
	ANIMDATA(_effect_smoke),
};

static TexAnim _effect_bomb[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_bomb_anim_data[] = {
	ANIMDATA(_effect_smoke),
};
static TexAnim _effect_slash[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};
TexAnimData effect_slash_anim_data[] = {
	ANIMDATA(_effect_slash),
};