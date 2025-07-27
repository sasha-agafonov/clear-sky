#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "fence.hpp"
#include "world/shape.hpp"

fence::fence()
{
    shape_ = new shape;
}

void fence::halfFence(struct material* bad_material)
{

    glPushMatrix();
    glScalef(0.3, 0.3, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.,0., -0.3);
    glRotatef(90. ,0, 1.,0.);
    glScalef(0.2, 0.2, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.,0.,1.1);
    glRotatef(90. ,0, 1.,0.);
    glScalef(0.2, 0.2, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

}

void fence::brokenFence(struct material* bad_material)
{
    glPushMatrix();

    glPushMatrix();
    glScalef(0.3, 0.3, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7, 0., -1.8);
    glRotatef(90, 1.,0.,0.);
    glRotatef(60, 0.,1.,0.);
    glScalef(0.3, 0.3, 2.);

    shape_->cube(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.85,0.,-0.45);
    glRotatef(135. ,0, 1.,0.);
    glScalef(0.2, 0.2, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

    glPopMatrix();
}

void fence::pole(struct material* bad_material)
{

    glPushMatrix();
    glScalef(0.3, 0.3, 2.);
    shape_->cube(bad_material);
    glPopMatrix();

}

void fence::drawFence(struct material* bad_material)
{
    glPushMatrix();
    glTranslatef(-13.3, 11.3, 0.);
    glRotatef(-70.5, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-11.8, 7.4, 0.);
    glRotatef(-50, 0., 0., 1.);
    brokenFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.3, 4.5, 0.);
    glRotatef(-29, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.6, 2.5, 0.);
    glRotatef(-20.5, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6, 1, 0.);
    glRotatef(-14, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.6, 0, 0.);
    glRotatef(-1, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.5, 0, 0.);
    glRotatef(14.5, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.5, 1, 0.);
    glRotatef(23, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14., 2.5, 0.);
    glRotatef(40, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17., 5., 0.);
    glRotatef(55, 0., 0., 1.);
    halfFence(bad_material);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.5, 8.5, 0.);
    glRotatef(55, 0., 0., 1.);
    pole(bad_material);
    glPopMatrix();
}
