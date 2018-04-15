#include <QString>
#include <QtTest>

#include "../../../Pr2/include/fraction.h"

class FractionTest : public QObject
{
    Q_OBJECT

public:
    FractionTest();

private Q_SLOTS:
    void sum();
    void sub();
};

FractionTest::FractionTest()
{
}

void FractionTest::sum()
{
    QCOMPARE(Fraction(1, 2, 3).sum(Fraction(0, 3, 4)), Fraction(2, 5, 12));
    QCOMPARE(Fraction(-1, 1, 2).sum(Fraction(1, 1, 2)), Fraction(0, 0, 2));
    QCOMPARE(Fraction(-1, 1, 2).sum(Fraction(1, 1, 3)), Fraction(0, -1, 6));
    QCOMPARE(Fraction(1, 2, 3).sum(Fraction(0, -3, 4)), Fraction(0, 11, 12));
    QCOMPARE(Fraction(3, 8, 18).sum(Fraction(5, 14, 17)), Fraction(9, 41, 153));

    QCOMPARE(Fraction(0, 3, 4).sum(Fraction(1, 2, 3)), Fraction(2, 5, 12));
    QCOMPARE(Fraction(1, 1, 2).sum(Fraction(-1, 1, 2)), Fraction(0, 0, 2));
    QCOMPARE(Fraction(1, 1, 3).sum(Fraction(-1, 1, 2)), Fraction(0, -1, 6));
    QCOMPARE(Fraction(0, -3, 4).sum(Fraction(1, 2, 3)), Fraction(0, 11, 12));
    QCOMPARE(Fraction(5, 14, 17).sum(Fraction(3, 8, 18)), Fraction(9, 41, 153));
}

void FractionTest::sub()
{
    QCOMPARE(Fraction(1, 2, 3).sub(Fraction(0, 3, 4)), Fraction(0, 11, 12));
    QCOMPARE(Fraction(-1, 1, 2).sub(Fraction(1, 1, 2)), Fraction(-3, 0, 1));
    QCOMPARE(Fraction(-1, 1, 2).sub(Fraction(1, 1, 3)), Fraction(-2, 5, 6));
    QCOMPARE(Fraction(1, 2, 3).sub(Fraction(0, -3, 4)), Fraction(2, 5, 12));
    QCOMPARE(Fraction(3, 8, 18).sub(Fraction(5, 14, 17)), Fraction(-2, 58, 153));

    QCOMPARE(Fraction(0, 3, 4).sub(Fraction(1, 2, 3)), Fraction(0, -11, 12));
    QCOMPARE(Fraction(1, 1, 2).sub(Fraction(-1, 1, 2)), Fraction(3, 0, 1));
    QCOMPARE(Fraction(1, 1, 3).sub(Fraction(-1, 1, 2)), Fraction(2, 5, 6));
    QCOMPARE(Fraction(0, -3, 4).sub(Fraction(1, 2, 3)), Fraction(-2, 5, 12));
    QCOMPARE(Fraction(5, 14, 17).sub(Fraction(3, 8, 18)), Fraction(2, 58, 153));
}

QTEST_APPLESS_MAIN(FractionTest)

#include "tst_fractiontest.moc"
