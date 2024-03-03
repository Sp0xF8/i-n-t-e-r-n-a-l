#include <menu.h>
#include <config.h>
#include <defines.h>

#include <string>

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

ImVec4 Float_To_ImVec4(float* colour) {
    return ImVec4(colour[0], colour[1], colour[2], colour[3]);
}

ImVec2 Int_To_ImVec2(int* size) {
    return ImVec2(size[0], size[1]);
}

void TextCentered(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;

    auto textHeight = ImGui::CalcTextSize(text.c_str()).y;
    auto windowHeight = ImGui::GetWindowSize().y;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::SetCursorPosY((windowHeight - textHeight) * 0.5f);
    ImGui::Text(text.c_str());
}



#define MAGNIFY_SIZE(x)				int(x * config::menu::magnification)
#define TABs 5

#define END_C						ImGui::EndChild();
#define SAMEL						ImGui::SameLine();

#define POP_STYLE					ImGui::PopStyleVar();
#define POP_COLOUR					ImGui::PopStyleColor();

#define WINDOW_SPACING				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(MAGNIFY_SIZE(8), MAGNIFY_SIZE(8)));
#define NO_WINDOW_SPACING			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

#define ITEM_SPACING				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2((MAGNIFY_SIZE(4)), (MAGNIFY_SIZE(4))));
#define NO_ITEM_SPACING				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));


#define HORIZONTAL_SPACING_8		ImGui::Dummy(ImVec2(MAGNIFY_SIZE(8), 0));
#define HORIZONTAL_SPACING_4		ImGui::Dummy(ImVec2(MAGNIFY_SIZE(4), 0));

#define VERTICAL_SPACING_8			ImGui::Dummy(ImVec2(0, MAGNIFY_SIZE(8)));
#define VERTICAL_SPACING_4			ImGui::Dummy(ImVec2(0, MAGNIFY_SIZE(4)));

#define ALL_SPACING					ImGui::Dummy(ImVec2(MAGNIFY_SIZE(4), MAGNIFY_SIZE(4)));
#define ALL_SPACING_8				ImGui::Dummy(ImVec2(MAGNIFY_SIZE(8), MAGNIFY_SIZE(8)));

#define COLOUR_SPACING				ImGui::Dummy(ImVec2(ImGui::GetContentRegionAvail().x - MAGNIFY_SIZE(50), 0)); SAMEL


namespace menu {
    ImVec2 bodysize = ImVec2(config::menu::size[0], config::menu::size[1] - config::menu::tabHeight);
    
    ImVec2 ButtonSize = ImVec2((config::menu::size[0] / TABs) - MAGNIFY_SIZE(6.4), config::menu::tabHeight - MAGNIFY_SIZE(7));

}
    




void menu::PopTheme(){

    ImGuiStyle* style = &ImGui::GetStyle();

    style->WindowMinSize = Int_To_ImVec2(config::menu::size);
    style->WindowPadding = ImVec2(0, 0);



    style->Colors[ImGuiCol_TitleBg] = Float_To_ImVec4(config::menu::colours::titleBg);
    style->Colors[ImGuiCol_TitleBgActive] = Float_To_ImVec4(config::menu::colours::titleBgActive);
    style->Colors[ImGuiCol_TitleBgCollapsed] = Float_To_ImVec4(config::menu::colours::titleBgCollapsed);

    style->Colors[ImGuiCol_Text] = Float_To_ImVec4(config::menu::colours::textCol1);

    style->Colors[ImGuiCol_Button] = Float_To_ImVec4(config::menu::colours::button);
    style->Colors[ImGuiCol_ButtonHovered] = Float_To_ImVec4(config::menu::colours::buttonHovered);
    style->Colors[ImGuiCol_ButtonActive] = Float_To_ImVec4(config::menu::colours::buttonActive);

    style->Colors[ImGuiCol_Separator] = Float_To_ImVec4(config::menu::colours::separator);
    style->Colors[ImGuiCol_SeparatorHovered] = Float_To_ImVec4(config::menu::colours::separatorHovered);
    style->Colors[ImGuiCol_SeparatorActive] = Float_To_ImVec4(config::menu::colours::separatorActive);

    style->Colors[ImGuiCol_WindowBg] = Float_To_ImVec4(config::menu::colours::windowBg);
    style->Colors[ImGuiCol_ChildBg] = Float_To_ImVec4(config::menu::colours::childBg);
    style->Colors[ImGuiCol_Border] = Float_To_ImVec4(config::menu::colours::borderBg);

    style->Colors[ImGuiCol_FrameBg] = Float_To_ImVec4(config::menu::colours::frameBg);
    style->Colors[ImGuiCol_FrameBgHovered] = Float_To_ImVec4(config::menu::colours::frameBgHover);
    style->Colors[ImGuiCol_FrameBgActive] = Float_To_ImVec4(config::menu::colours::frameBgActive);

    style->Colors[ImGuiCol_Header] = Float_To_ImVec4(config::menu::colours::headder);
    style->Colors[ImGuiCol_HeaderHovered] = Float_To_ImVec4(config::menu::colours::headderHover);
    style->Colors[ImGuiCol_HeaderActive] = Float_To_ImVec4(config::menu::colours::headderActive);

    style->Colors[ImGuiCol_CheckMark] = Float_To_ImVec4(config::menu::colours::checkMark);

    style->Colors[ImGuiCol_SliderGrab] = Float_To_ImVec4(config::menu::colours::sliderGrab);
    style->Colors[ImGuiCol_SliderGrabActive] = Float_To_ImVec4(config::menu::colours::sliderGrabActive);

    style->Colors[ImGuiCol_ScrollbarBg] = Float_To_ImVec4(config::menu::colours::scrollBar);
    style->Colors[ImGuiCol_ScrollbarGrab] = Float_To_ImVec4(config::menu::colours::scrollBarGrab);
    style->Colors[ImGuiCol_ScrollbarGrabHovered] = Float_To_ImVec4(config::menu::colours::scrollBarHovered);
    style->Colors[ImGuiCol_ScrollbarGrabActive] = Float_To_ImVec4(config::menu::colours::scrollBarActive);


}

void menu::DrawMenu(){

    NO_WINDOW_SPACING

    ImGui::BeginChild("##top", bodysize, true);
    {
        NO_ITEM_SPACING
        NO_WINDOW_SPACING
        ImGui::Dummy(ImVec2(bodysize.x, MAGNIFY_SIZE(10)));

        HORIZONTAL_SPACING_8
        SAMEL

        switch (config::menu::tabIndex)
        {
        case 0: //Legit
            
            ImGui::Text("Legit");

            break;
        case 1: //Rage
            
            ImGui::Text("Rage");

            break;
        case 2: //Visuals

            ImGui::PushStyleColor(ImGuiCol_ChildBg, Float_To_ImVec4(config::menu::colours::categoryHeadderColour));
            ImGui::BeginChild("##VisualsHeadder", ImVec2(bodysize.x / 3, config::menu::tabHeight), true);
            {
                TextCentered("Visuals");
            }
            END_C
            POP_COLOUR

            HORIZONTAL_SPACING_8
            SAMEL

            ImGui::PushStyleColor(ImGuiCol_ChildBg, Float_To_ImVec4(config::menu::colours::categoryBodyColour));
            ImGui::BeginChild("##VisualsBody", ImVec2(bodysize.x / 3, ImGui::GetContentRegionAvail().y - MAGNIFY_SIZE(10)), true);
            {
				WINDOW_SPACING
				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(MAGNIFY_SIZE(2), MAGNIFY_SIZE(4)));
                
                ImGui::Checkbox("Enabled", &config::visuals::enabled); SAMEL
				ImGui::Checkbox("Draw Team", &config::visuals::drawTeam); 

				ImGui::Checkbox("Box", &config::visuals::esp::box); SAMEL
				COLOUR_SPACING SAMEL
				ImGui::ColorEdit4("#BoxColour", config::visuals::esp::boxColour, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Health", &config::visuals::esp::health); 

				ImGui::Checkbox("Name", &config::visuals::esp::name); SAMEL
				COLOUR_SPACING SAMEL
				ImGui::ColorEdit4("#NameColour", config::visuals::esp::nameColour, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Weapon", &config::visuals::esp::weapon); SAMEL
				COLOUR_SPACING SAMEL
				ImGui::ColorEdit4("#WeaponColour", config::visuals::esp::weaponColour, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				
				ImGui::Checkbox("Skeleton", &config::visuals::esp::skeleton); SAMEL
				COLOUR_SPACING SAMEL
				ImGui::ColorEdit4("#SkeletonColour", config::visuals::esp::skeletonColour, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Checkbox("Snaplines", &config::visuals::esp::snaplines); SAMEL
				COLOUR_SPACING SAMEL
				ImGui::ColorEdit4("#SnaplineColour", config::visuals::esp::snaplineColour, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				

				POP_STYLE
				POP_STYLE
            }
            END_C
            POP_COLOUR

            break;
        case 3: //Misc
                    
            ImGui::Text("Misc");

            if(config::visuals::esp::name){
                ImGui::Text("PlayerList");
            }

            break;

        case 4: //Settings
                        
            ImGui::Text("Settings");

            break;
        default:
            ImGui::Text("Error::InvalidTabIndex");
            break;
        }

        POP_STYLE
        POP_STYLE
    }
    END_C

    POP_STYLE

    
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(MAGNIFY_SIZE(4), MAGNIFY_SIZE(5)));
    ALL_SPACING
    SAMEL


    if (ImGui::Button("Legit", menu::ButtonSize)) {
        config::menu::tabIndex = 0;
    }
    SAMEL

    if (ImGui::Button("Rage", menu::ButtonSize)) {
        config::menu::tabIndex = 1;
    }
    SAMEL

    if (ImGui::Button("Visuals", menu::ButtonSize)) {
        config::menu::tabIndex = 2;
    }
    SAMEL

    if (ImGui::Button("Misc", menu::ButtonSize)) {
        config::menu::tabIndex = 3;
    }
    SAMEL

    if (ImGui::Button("Settings ", menu::ButtonSize)) {
        config::menu::tabIndex = 4;
    }
    SAMEL
    

	POP_STYLE



    
    

}