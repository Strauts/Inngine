#ifndef MAT4_H
#define MAT4_H

#include "vec3.h"
#include "vec4.h"
#include "gltypes.h"
#include <iostream>
#include <iomanip>

namespace gsl
{

    class Mat2;
    class Mat3;
    class Quaternion;

    //This matrix class is based on Lars M. Nylands branch!
    class Mat4
    {
        public:
            Mat4(bool isIdentity = false);
            Mat4(std::initializer_list<GLfloat> values);

            Mat4 identity();
            void setToIdentity();

            bool inverse();

            void translateX(GLfloat x = 0.f);
            void translateY(GLfloat y = 0.f);
            void translateZ(GLfloat z = 0.f);

            //Rotate using EulerMatrix
            void rotateX(GLfloat degrees = 0.f);
            void rotateY(GLfloat degrees = 0.f);
            void rotateZ(GLfloat degrees = 0.f);

            //Rotate using Quaternion
            void qRotateX(GLfloat degrees = 0.f);
            void qRotateY(GLfloat degrees = 0.f);
            void qRotateZ(GLfloat degrees = 0.f);

            //Rotate the matrix using an angle and an axis
            void rotate(Quaternion &quat);
            void rotate(GLfloat angle, const Vec3 &vector);
            void rotate(GLfloat angle, GLfloat xIn, GLfloat yIn, GLfloat zIn);

            void scale(Vec3 s);
            void scale(GLfloat uniformScale = 1.f);
            void scale(GLfloat scaleX = 1.f, GLfloat scaleY = 1.f, GLfloat scaleZ = 1.f);

            GLfloat* constData();

            void transpose();

            void ortho(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat nearPlane, GLfloat farPlane);
            void perspective(GLfloat verticalAngle, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane);

            void lookAt(const Vec3 &eye, const Vec3 &center, const Vec3 &up_axis);

            void translate(GLfloat x = 0.f, GLfloat y = 0.f, GLfloat z = 0.f);
            void translate(Vec3 positionIn);

            Mat2 toMatrix2();
            Mat3 toMatrix3();

            GLfloat& operator()(const int &y, const int &x);
            GLfloat operator()(const int &y, const int &x) const;

            Mat4 operator*(const Mat4 &other);

            Vec4 operator*(const Vec4 &other);

            friend std::ostream& operator<<(std::ostream &output, const Mat4 &mIn)
            {
                output << std::setprecision(4) <<
                          "{" << mIn.matrix[0] << "\t, " << mIn.matrix[4] << "\t, " << mIn.matrix[8] << "\t, " << mIn.matrix[12] << "}\n" <<
                          "{" << mIn.matrix[1] << "\t, " << mIn.matrix[5] << "\t, " << mIn.matrix[9] << "\t, " << mIn.matrix[13] << "}\n" <<
                          "{" << mIn.matrix[2] << "\t, " << mIn.matrix[6] << "\t, " << mIn.matrix[10] << "\t, " << mIn.matrix[14] << "}\n" <<
                          "{" << mIn.matrix[3] << "\t, " << mIn.matrix[7] << "\t, " << mIn.matrix[11] << "\t, " << mIn.matrix[15] << "}\n";
                return output;
            }

        private:
            GLfloat matrix[16];
    };

} //namespace
#endif // MAT4_H
