//LED representation of heart beat.

unsigned int ledPin = 13;

int beatTime = 1500; //800 milliseconds for one beat.

double minPressure = 80; //80mm Hg
double minGlow = 5;
double minPressureTime = beatTime / 2; //estimated

extern int ledOutput = minGlow;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

double aorticPressure = 120; //120mm Hg
double aorticGlow = 200;
double aorticPressureTime = beatTime / 4; //estimated

double afterAorticPressureFall = 100; //mmHg
double afterAorticFallGlow = map(afterAorticPressureFall, 80,120 , 0,200 );
double afterAorticTime = 1500 / 8; //estimated

double ventriolicPressure = 110; //mmHg
double ventriolicGlow = map(ventriolicPressure, 80,120 , 0,200 );
double ventriolicTime = beatTime / 8; //estimated

double aorticGlowTimeUnit = aorticPressureTime / ((aorticGlow - minGlow) / 5);
double minGlowTimeUnit = minPressureTime / ((ventriolicGlow - minGlow) / 5);
double afterAorticGlowTimeUnit = afterAorticTime / ((aorticGlow - afterAorticFallGlow) / 5);
double ventriolicGlowTimeUnit = ventriolicTime / ((ventriolicGlow - afterAorticFallGlow) / 5);



void loop()
{
  plotter(aorticGlow,aorticGlowTimeUnit,1);
  plotter(afterAorticFallGlow,afterAorticGlowTimeUnit,0);
  //delay(50);
  plotter(ventriolicGlow,ventriolicGlowTimeUnit,1);
  plotter(minGlow,minGlowTimeUnit,0);
}

int plotter(double glow, double unitTime,bool slope)
{
  if (slope)
  {
    for (; ledOutput <= glow; ledOutput *= 5)
    {
      analogWrite(ledPin,ledOutput);
      delay(unitTime*5);
    }
  }
   else
  { 
    for (; ledOutput >= glow; ledOutput /= 5)
    {
      analogWrite(ledPin,ledOutput);
      delay(unitTime*5);
    }
    
  }
}
