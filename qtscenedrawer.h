#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include "scenedrawerbase.h"
#include <QGraphicsScene>

class QtSceneDrawer: public SceneDrawerBase {
private:
    QGraphicsScene* qScene;
    void drawLine(Vertex& vert1, Vertex& vert2);
public:
    explicit QtSceneDrawer(QGraphicsScene* scene);
    void DrawScene(Scene& scene) override;
    void clear() override;
    void DrawAxes(float axisLength);
};

#endif // QTSCENEDRAWER_
