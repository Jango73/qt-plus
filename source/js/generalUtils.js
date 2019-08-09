
//-------------------------------------------------------------------------------------------------
// String functions

String.prototype.format = function () {
    var a = this.slice(0);
    for (var k in arguments) {
        a = a.replace(new RegExp("\\{" + k + "\\}", 'g'), arguments[k]);
    }
    return a
}

String.prototype.pad = function(value, count) {
    var str = "" + value
    while (str.length < count) {
        str = '0' + str
    }
    return str
}

//-------------------------------------------------------------------------------------------------
// Math functions

function isNaN(value) {
    var data = Number(value)
    return data !== data
}

function signOf(value) {
    return value >= 0 ? 1 : -1
}

function fract(a)
{
    return a - Math.floor(a);
}

function mix(s, e, v)
{
    return s * (1.0 - v) + e * v
}

function toFixed(value, digits) {
    var power = Math.pow(10, digits || 0)
    return Math.round(value * power) / power
}

function toDMS(value) {
    var d = Math.floor(value);
    var minfloat = (value - d) * 60.0;
    var m = Math.floor(minfloat);
    var secfloat = (minfloat - m) * 60.0;
    var s = Math.round(secfloat);

    // After rounding, the seconds might become 60. These two
    // if-tests are not necessary if no rounding is done.

    if (s === 60) {
        m++;
        s = 0;
    }

    if (m === 60) {
        d++;
        m = 0;
    }

    return "" + d + "° " + m + "' " + s + "''"
}

function addMinutesToDate(date, minutes) {
    return new Date(date.getTime() + minutes * 60000)
}

function addSecondsToDate(date, seconds) {
    return new Date(date.getTime() + seconds * 1000)
}

function formatHoursMinutesFromDate(date) {
    return formatHoursMinutes(date.getHours(), date.getMinutes())
}

function formatHoursMinutes(hours, minutes) {
    return zeroPadded(hours, 2) + ":" + zeroPadded(minutes, 2)
}

function inputLevelOrAltitudeToAltitude(value) {
    return value < 500 ? value * 100 : value
}

function snap(value, amount) {
    value = amount * Math.round(value / amount)
    return value
}

function rollingValueClipped(value, bound) {
    if (isNaN(value))
        return 0.0

    if (value > 10000.0)
        return 0.0

    if (value < -10000.0)
        return 0.0

    while (value < 0) value += bound
    while (value > bound) value -= bound
    return value
}

function rollingValueClippedAsAngle(value, bound) {
    if (isNaN(value))
        return 0.0

    if (value > 10000.0)
        return 0.0

    if (value < -10000.0)
        return 0.0

    while (value < -bound * 0.5) value += bound
    while (value > bound * 0.5) value -= bound
    return value
}

function headingClipped(value, round) {
    value = angleClipped(value)
    value = value;

    // [0, 0.5[  =>  360°
    if ( 0 <= value && value < 0.5) {
        value = 360
    }
    // [0.5, 1[  =>  1°
    else if ( 0.5 <= value && value < 1) {
        value = 1
    }

    return Number(round ? Math.round(value) : value.toFixed(2))
}

function angleClipped(value) {
    if (isNaN(value))
        return 0.0

    if (value > 10000.0)
        return 0.0

    if (value < -10000.0)
        return 0.0

    while (value < 0) value += 360
    while (value > 360) value -= 360
    return value
}

function angleHalfClipped(value) {
    if (isNaN(value))
        return 0.0

    if (value > 10000.0)
        return 0.0

    if (value < -10000.0)
        return 0.0

    while (value < -180) value += 360
    while (value > 180) value -= 360
    return value
}

function angleDifference(angle1, angle2) {
    var a = angle1 - angle2
    a += (a > 180) ? -360 : (a < -180) ? 360 : 0
    return a
}

function clippedValue(value, min, max) {
    if (value < min) value = min
    if (value > max) value = max

    return value
}

function ensureInBounds(rect, boundItem) {
    if (rect.y + rect.height > boundItem.height) {
        rect.y = boundItem.height - popupActionMenu.height
    }

    if (rect.y < 0) {
        rect.y = 0
    }
}

function cubicCurve(x, a, b, c, d) {
    return a * Math.pow(x, 3) + b * Math.pow(x, 2) + c * x + d
}

function lineIntersection(x1, y1, x2, y2, x3, y3, x4, y4) {
    // Check if none of the lines are of length 0
    if ((x1 === x2 && y1 === y2) || (x3 === x4 && y3 === y4)) {
        return null
    }

    var denominator = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1))

    // Lines are parallel
    if (denominator === 0) {
        return null
    }

    var ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denominator
    var ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denominator

    // is the intersection along the segments
    //    if (ua < 0 || ua > 1 || ub < 0 || ub > 1) {
    //        return null
    //    }

    // Return a object with the x and y coordinates of the intersection
    var x = x1 + ua * (x2 - x1)
    var y = y1 + ua * (y2 - y1)

    return { x: x, y: y }
}

//-------------------------------------------------------------------------------------------------
// Conversion functions

function degreesToRadians(value) {
    return (value / 180.0) * Math.PI
}

function radiansToDegrees(value) {
    return (value / Math.PI) * 180.0
}

function knotsToKilometersPerHour(value) {
    return value * 1.852
}

function knotsToMetersPerSecond(value) {
    return value * 0.514444
}

function knotsToFeetPerMinute(value) {
    return value * 101.269
}

function metersPerSecondToKnots(value) {
    return value * 1.94384
}

function metersPerSecondToFeetPerMinute(value) {
    return metersToFeet(value) * 60
}

function metersPerSecondToKnots(value) {
    return value * 1.94384
}

function feetPerSecondToKnots(value) {
    return value * 0.592484
}

function nauticalMilesToMeters(value) {
    return value * 1852.0
}

function nauticalMilesToKilometers(value) {
    return value * 1.852
}

function metersToNauticalMiles(value) {
    return value * 0.000539957
}

function feetToMeters(value) {
    return value * 0.3048
}

function metersToFeet(value) {
    return value * 3.28084
}

//-------------------------------------------------------------------------------------------------
// Time functions

function timeString(time) {
    return ""
            + zeroPadded(Math.floor(time / 3600), 2)
            + ":" + zeroPadded(Math.floor(time / 60), 2)
            + ":" + zeroPadded(Math.floor(time % 60), 2)
            + ":" + zeroPadded(Math.floor(time % 1 * 100))
}

//-------------------------------------------------------------------------------------------------
// Interpolation functions
// input: any number
// table: [ { input: 0, output: 10 }, { input: 100, output: 250 }, ... ]

function linearInterpolate(input, table) {
    var output = 0

    if (table.length === 0)
        return output

    if (input < table[0].input)
        input = table[0].input

    if (input > table[table.length - 1].input)
        input = table[table.length - 1].input

    for (var index = 0; index < table.length; index++) {
        if (input >= table[index].input) {
            if (index < table.length - 1) {
                if (input <= table[index + 1].input) {
                    var input1 = table[index + 0].input
                    var input2 = table[index + 1].input
                    var inputRange = input2 - input1

                    var output1 = table[index + 0].output
                    var output2 = table[index + 1].output
                    var outputRange = output2 - output1

                    var factor = (input - input1) / inputRange
                    output = output1 + (outputRange * factor)

                    break
                }
            } else {
                output = table[index].output
            }
        }
    }

    return output
}

//-------------------------------------------------------------------------------------------------
// File functions

function openFile(path) {
    var xhr = new XMLHttpRequest()

    xhr.open('GET', path, false)
    xhr.send(null)

    if (xhr.status === 200) {
        return xhr.responseText
    }

    return ""
}

//-------------------------------------------------------------------------------------------------
// Search functions

function searchArray(arr, blockAccept, dataAccept) {
    if (arr.length === 0)
        return -1

    return searchArrayRecurse(arr, blockAccept, dataAccept, 0, arr.length - 1)
}

function searchArrayRecurse(arr, blockAccept, dataAccept, start, end) {

    if (blockAccept(arr, start, end) === false)
        return -1

    if (dataAccept(arr, start))
        return start

    start++

    if (end - start > 1) {
        var half = Math.floor(start + (end - start) * 0.5)
        var half2 = half + 1

        if (half - start > 0) {
            var lo = searchArrayRecurse(arr, blockAccept, dataAccept, start, half)
            if (lo !== -1)
                return lo
        }

        if (end - (half2) > 0) {
            var hi = searchArrayRecurse(arr, blockAccept, dataAccept, half2, end)
            if (hi !== -1)
                return hi
        }
    } else {
        if (dataAccept(arr, start))
            return start

        if (dataAccept(arr, end))
            return end
    }

    return -1
}

function searchArrayTest() {
    var arr = [ 0, 2, 4, 8, 16, 20 ]

    var value = 4.5
    var index = searchArray(arr,
                            function(arr, start, end) {
                                return !(arr[start] < value && arr[end] < value)
                            },
                            function(arr, start) {
                                return arr[start] >= value
                            }
                            )

    index = (index > 1 ? index - 1 : index)

    console.log("searchArrayTest: for " + value + ", result (i,v) = " + index + ", " + arr[index] )
}

//-------------------------------------------------------------------------------------------------
// Canvas functions

function line(context, x1, y1, x2, y2, color) {
    context.strokeStyle = color

    context.beginPath()
    context.moveTo(x1, y1)
    context.lineTo(x2, y2)
    context.stroke()
}

function getLargestText(lines) {
    var largestIndex = 0
    var largestSize = 0

    for (var index = 0; index < lines.length; index++) {
        var length = lines[index].length
        if (length > largestSize) {
            largestIndex = index
            largestSize = length
        }
    }

    return lines[largestIndex]
}

function rectangleText(context, fontSize, x, y, text, textColor, backgroundColor) {
    var lines = text.split('\n');

    var textSize = context.measureText(getLargestText(lines))
    var interLine = 2
    var expand = 10

    textSize.width = textSize.width + expand
    textSize.height = ((lines.length * fontSize) + expand) + ((lines.length - 1) * interLine)

    context.fillStyle = backgroundColor
    context.fillRect(x - textSize.width * 0.5, y - textSize.height * 0.5, textSize.width, textSize.height)

    context.fillStyle = textColor

    var drawY = (y - (fontSize * (lines.length - 1)) * 0.5) + interLine * 0.5

    for (var index = 0; index < lines.length; index++) {
        context.fillText(lines[index], x, drawY)
        drawY += fontSize + interLine
    }
}

//--------------------------------------------------------------------------------
// Color functions

function componentToHex(value) {
    var hex = value.toString(16)
    return hex.length === 1 ? "0" + hex : hex
}

function rgbToHex(r, g, b) {
    return "#" + componentToHex(r) + componentToHex(g) + componentToHex(b)
}

function hexToRgb(hex) {
    var str = String(hex)
    var bigint = parseInt(str.slice(1), 16)
    var r = (bigint >> 16) & 255
    var g = (bigint >> 8) & 255
    var b = bigint & 255

    return { r: r, g: g, b: b }
}

function multipliedColor(color, factor) {
    var rgb = hexToRgb(color)

    // return rgb !== null ? rgbToHex(rgb.r * factor, rgb.g * factor, rgb.b * factor) : "#888"

    if (rgb === null)
        return "#888"

    rgb.r *= factor
    rgb.g *= factor
    rgb.b *= factor

    rgb.r = Math.round(Math.min(Math.max(rgb.r, 0), 255))
    rgb.g = Math.round(Math.min(Math.max(rgb.g, 0), 255))
    rgb.b = Math.round(Math.min(Math.max(rgb.b, 0), 255))

    var result = rgbToHex(rgb.r, rgb.g, rgb.b)

    return result
}

function rgbToGray(rgb) {
    return (rgb.r * 0.2125) + (rgb.g * 0.7154) + (rgb.b * 0.0721)
}

function contrastedColor(color) {
    var rgb = hexToRgb(color)
    var mono = rgbToGray(rgb) / 255
    var value = mono < 0.4 ? "#DDD" : "#222"

    return value
}

function contrastedColorInverse(color) {
    var rgb = hexToRgb(color)
    var mono = rgbToGray(rgb) / 255
    var value = mono < 0.4 ? "#222" : "#DDD"

    return value
}

function adjustedColor(color) {
    var rgb = hexToRgb(color)
    var mono = rgbToGray(rgb) / 255

    return mono < 0.2 ? multipliedColor(color, 2) : color
}

function tintedColor(color, tintColor) {
    var rgb1 = hexToRgb(color)
    var rgb2 = hexToRgb(tintColor)
    var hsv1 = rgbToHsv(rgb1.r, rgb1.g, rgb1.b)
    var hsv2 = rgbToHsv(rgb2.r, rgb2.g, rgb2.b)
    hsv1.h = hsv2.h
    rgb1 = hsvToRgb(hsv1.h, hsv1.s, hsv1.v)

    return rgbToHex(rgb1)
}

function itemInsideParent(item) {
    return (item.x + item.width <= item.parent.width)
}

//--------------------------------------------------------------------------------
// Color functions from https://github.com/bgrins/TinyColor
// (c) Brian Grinstead

// Check to see if string passed in is a percentage
function isPercentage(n) {
    return typeof n === "string" && n.indexOf('%') !== -1;
}

// Need to handle 1.0 as 100%, since once it is a number, there is no difference between it and 1
// <http://stackoverflow.com/questions/7422072/javascript-how-to-detect-number-as-a-decimal-including-1-0>
function isOnePointZero(n) {
    return typeof n == "string" && n.indexOf('.') !== -1 && parseFloat(n) === 1;
}

// Take input from [0, n] and return it as [0, 1]
function bound01(n, max) {
    if (isOnePointZero(n)) { n = "100%"; }

    var processPercent = isPercentage(n);
    n = Math.min(max, Math.max(0, parseFloat(n)));

    // Automatically convert percentage into number
    if (processPercent) {
        n = parseInt(n * max, 10) / 100;
    }

    // Handle floating point rounding errors
    if ((Math.abs(n - max) < 0.000001)) {
        return 1;
    }

    // Convert into [0, 1] range if it isn't already
    return (n % max) / parseFloat(max);
}

// `rgbToHsv`
// Converts an RGB color value to HSV
// *Assumes:* r, g, and b are contained in the set [0, 255] or [0, 1]
// *Returns:* { h, s, v } in [0,1]
function rgbToHsv(r, g, b) {

    r = bound01(r, 255);
    g = bound01(g, 255);
    b = bound01(b, 255);

    var max = Math.max(r, g, b), min = Math.min(r, g, b);
    var h, s, v = max;

    var d = max - min;
    s = max === 0 ? 0 : d / max;

    if (max === min) {
        h = 0; // achromatic
    }
    else {
        switch(max) {
            case r: h = (g - b) / d + (g < b ? 6 : 0); break;
            case g: h = (b - r) / d + 2; break;
            case b: h = (r - g) / d + 4; break;
        }
        h /= 6;
    }
    return { h: h, s: s, v: v };
}

// `hsvToRgb`
// Converts an HSV color value to RGB.
// *Assumes:* h is contained in [0, 1] or [0, 360] and s and v are contained in [0, 1] or [0, 100]
// *Returns:* { r, g, b } in the set [0, 255]
 function hsvToRgb(h, s, v) {

    h = bound01(h, 360) * 6;
    s = bound01(s, 100);
    v = bound01(v, 100);

    var i = Math.floor(h),
        f = h - i,
        p = v * (1 - s),
        q = v * (1 - f * s),
        t = v * (1 - (1 - f) * s),
        mod = i % 6,
        r = [v, q, p, p, t, v][mod],
        g = [t, v, v, q, p, p][mod],
        b = [p, p, t, v, v, q][mod];

    return { r: r * 255, g: g * 255, b: b * 255 };
}
