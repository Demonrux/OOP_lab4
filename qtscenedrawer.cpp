#include "qtscenedrawer.h"
#include "figure.h"
#include "edge.h"
#include "vertex.h"
#include <QPen>
#include <QColor>

QtSceneDrawer::QtSceneDrawer(QGraphicsScene* scene) : qScene(scene){}

void QtSceneDrawer::DrawScene(Scene& scene) {
    if (!qScene) return;

    DrawAxes(Constants::AXIS_LENGTH);

    for(auto& figure : scene.getFigures()) {
        for(auto& edge : figure->getEdges()) {
            auto& vert1 = edge.getBegin();
            auto& vert2 = edge.getEnd();
            drawLine(vert1, vert2);
        }
    }
}

void QtSceneDrawer::drawLine(Vertex& vert1, Vertex& vert2) {
    QPen pen(QColor(100, 200, 255));
    pen.setWidthF(Constants::LINE_WIDTH);
    qScene->addLine(vert1.getPosition().x, -vert1.getPosition().y,  vert2.getPosition().x, -vert2.getPosition().y, pen);
}

void QtSceneDrawer::DrawAxes(float axisLength) {
    if (!qScene) return;

    QPen xPen(Qt::red);
    xPen.setWidthF(Constants::AXIS_WIDTH);
    qScene->addLine(0, 0, axisLength, 0, xPen);

    QPen yPen(Qt::green);
    yPen.setWidthF(Constants::AXIS_WIDTH);
    qScene->addLine(0, 0, 0, -axisLength, yPen);

    QPen zPen(Qt::blue);
    zPen.setWidthF(Constants::AXIS_WIDTH);
    qScene->addLine(0, 0, 0, axisLength * 0.2, zPen);
}

void QtSceneDrawer::clear() {
    if (qScene) qScene->clear();
}
