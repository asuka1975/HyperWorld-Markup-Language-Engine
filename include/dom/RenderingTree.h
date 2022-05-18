//
// Created by hungr on 2022/05/18.
//

#ifndef HYPERWORLD_MARKUP_LANGUAGE_ENGINE_RENDERINGTREE_H
#define HYPERWORLD_MARKUP_LANGUAGE_ENGINE_RENDERINGTREE_H

#include "dom/CascadingStyleSheetsObjectModel.h"
#include "dom/DocumentObjectModel.h"

namespace hwml_engine::dom::hwml {
    class RenderingTree {
    public:
        RenderingTree(DocumentObjectModel& dom, CascadingStyleSheetsObjectModel& cssom);
    };
}

#endif //HYPERWORLD_MARKUP_LANGUAGE_ENGINE_RENDERINGTREE_H
