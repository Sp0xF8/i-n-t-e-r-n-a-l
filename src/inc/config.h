#pragma once



namespace config {
    namespace menu {
        extern float magnification;
        extern bool isOpen;
        extern int size[2];
        extern int tabHeight;
		extern int tabIndex;

        namespace colours {
            extern float titleBg[4];
			extern float titleBgActive[4];
			extern float titleBgCollapsed[4];

			extern float textCol1[4];

			extern float button[4];
			extern float buttonHovered[4];
			extern float buttonActive[4];

			extern float separator[4];
			extern float separatorHovered[4];
			extern float separatorActive[4];

			extern float windowBg[4];
			extern float childBg[4];
			extern float borderBg[4];

			extern float frameBg[4];
			extern float frameBgHover[4];
			extern float frameBgActive[4];

			extern float headder[4];
			extern float headderHover[4];
			extern float headderActive[4];

			extern float checkMark[4];

			extern float sliderGrab[4];
			extern float sliderGrabActive[4];

			extern float scrollBar[4];
			extern float scrollBarGrab[4];
			extern float scrollBarHovered[4];
			extern float scrollBarActive[4];


			extern float textHeadderColour[4];

			extern float categoryHeadderColour[4];
			extern float categoryBodyColour[4];
        }

    }

	namespace visuals {
		extern bool enabled;

		extern bool drawTeam;
		namespace esp {
			extern bool box;
			extern float boxColour[4];

			extern bool name;
			extern float nameColour[4];
			
			extern bool health;

			extern bool weapon;
			extern float weaponColour[4];

			extern bool skeleton;
			extern float skeletonColour[4];

			extern bool snaplines;
			extern float snaplineColour[4];

		}
	}

	namespace legitbot {
		extern bool enabled;

		namespace triggerbot {
			extern bool enabled;
			extern bool onKey;
			extern int key;
			extern bool friendlyFire;
			extern bool scopedOnly;
			extern bool ignoreJump;
			extern bool ignoreFlash;
			extern float flashAlpha;
			extern bool ignoreSmoke;
			extern bool delayShot;
			extern int delay;
		}
	}


	namespace misc {
		extern bool enabled;
		extern bool bunnyhop;
	}
}