#include <config.h>


namespace config {

    namespace menu {
        float magnification = 1.0f;

        bool isOpen = false;
        int size[2] = { 900, 400 };
        int tabHeight = 50;

        int tabIndex = 0;

        namespace colours {
            float titleBg[4]		  = {0.32f, 0.00f, 0.47f, 1.00f};
			float titleBgActive[4]	  = {0.32f, 0.00f, 0.47f, 1.00f};
			float titleBgCollapsed[4] = {0.00f, 0.00f, 0.00f, 1.00f};

			float textCol1[4] = {1.00f, 1.00f, 1.00f, 1.00f};

			float button[4]		   = {0.30f, 0.00f, 0.13f, 1.00f};
			float buttonHovered[4] = {0.12f, 0.11f, 0.12f, 1.00f};
			float buttonActive[4]  = {0.71f, 0.00f, 0.29f, 1.00f};

			float separator[4]		  = {0.30f, 0.00f, 0.13f, 1.00f};
			float separatorHovered[4] = {0.12f, 0.11f, 0.12f, 1.00f};
			float separatorActive[4]  = {0.71f, 0.00f, 0.29f, 1.00f};

			float windowBg[4] = {0.06f, 0.06f, 0.06f, 0.94f};
			float childBg[4]  = {0.00f, 0.00f, 0.00f, 0.00f};
			float borderBg[4] = {0.27f, 0.00f, 0.11f, 1.00f};

			float frameBg[4]	   = {0.30f, 0.00f, 0.13f, 1.00f};
			float frameBgHover[4]  = {0.12f, 0.11f, 0.12f, 1.00f};
			float frameBgActive[4] = {0.30f, 0.00f, 0.13f, 1.00f};

			float headder[4]	   = {0.30f, 0.00f, 0.13f, 1.00f};
			float headderHover[4]  = {0.12f, 0.11f, 0.12f, 1.00f};
			float headderActive[4] = {0.30f, 0.00f, 0.13f, 1.00f};

			float checkMark[4] = {0.71f, 0.00f, 0.29f, 1.00f};

			float sliderGrab[4]		  = {0.30f, 0.00f, 0.13f, 1.00f};
			float sliderGrabActive[4] = {0.71f, 0.00f, 0.29f, 1.00f};

			float scrollBar[4]		  = {0.30f, 0.00f, 0.13f, 1.00f};
			float scrollBarGrab[4]	  = {0.71f, 0.00f, 0.29f, 1.00f};
			float scrollBarHovered[4] = {0.12f, 0.11f, 0.12f, 1.00f};
			float scrollBarActive[4]  = {0.71f, 0.00f, 0.29f, 1.00f};

            float textHeadderColour[4] = {0.71f, 0.00f, 0.29f, 1.00f};

            float categoryHeadderColour[4] = {0.71f, 0.00f, 0.29f, 1.00f};
            float categoryBodyColour[4] = {0.30f, 0.00f, 0.13f, 1.00f};
        }
    }

    namespace visuals{
        bool enabled = false;

		bool drawTeam = false;
        namespace esp {
            bool box = false;
            float boxColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool dot = false;
			float dotColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

            bool name = false;
            float nameColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

            bool health = false;

			bool distance = false;
			float distanceColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };
			float distanceLimit = 1000.0f;
			
			bool weapon = false;
			float weaponColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool ammo = false;
			float ammoColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool bomb = false;
			float bombColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool armor = false;
			float armorColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool skeleton = false;
			float skeletonColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };

			bool snaplines = false;
			float snaplineColour[4] = { 0.71f, 0.00f, 0.29f, 1.00f };


        }
    }


	namespace legitbot {
		bool enabled = false;

		namespace triggerbot {
			bool enabled = false;
			bool onKey = false;
			int key = 0x46;
			bool friendlyFire = false;
			bool scopedOnly = false;
			bool ignoreJump = false;
			bool ignoreFlash = false;
			float flashAlpha = 0.0f;
			bool ignoreSmoke = false;
			bool delayShot = false;
			int delay = 0;

		}

	}

	namespace misc {
		bool enabled = false;
		bool bunnyhop = false;
	}
}