(function($) {
    var p = '';
    var fp = '';
    if ('azexo_prefix' in window) {
        p = window.azexo_prefix;
        fp = window.azexo_prefix.replace('-', '_');
    }

    function t(text) {
        if ('azexo_t' in window) {
            return window.azexo_t(text);
        } else {
            return text;
        }
    }

    var azexo_elements = [
        {
            base: 'az_countdown',
            name: t('Countdown Timer'),
            icon: 'fa fa-clock-o',
            description: t('Place countdown element'),
            params: [
                {
                    type: 'dropdown',
                    heading: t('Countdown style'),
                    param_name: 'countdown_style',
                    description: t('Select the style for the countdown element.'),
                    value: {
                        'style1': t('Style 1'),
                        'style2': t('Style 2'),
                        'style3': t('Style 3'),
                        'style4': t('Style 4'),
                        'style5': t('Style 5'),
                        'style6': t('Style 6'),
                        'style7': t('Style 7'),
                        'style8': t('Style 8'),
                        'style9': t('Style 9'),
                        'style10': t('Style 10'),
                    },
                },
                {
                    type: 'dropdown',
                    heading: t('Date / Time Limitations'),
                    param_name: 'counter_scope',
                    description: t('Select the countdown scope in terms of date and time.'),
                    value: {
                        'date': t('Specify Date Only'),
                        'date_time': t('Specify Date and Time'),
                        'repeating': t('Specifiy Time Only (repeating on every day)'),
                        'resetting': t('Resetting Counter (set interval up to 24 hours)'),
                    },
                },
                {
                    type: 'datetime',
                    heading: t('Date'),
                    param_name: 'date',
                    datepicker: true,
                    description: t('Select the date to which you want to count down to.'),
                    formatDate: 'd.m.Y',
                    dependency: {'element': 'counter_scope', 'value': ['date']},
                },
                {
                    type: 'datetime',
                    heading: t('Date / Time'),
                    param_name: 'date_time',
                    timepicker: true,
                    datepicker: true,
                    description: t('Select the date and time to which you want to count down to.'),
                    formatDate: 'd.m.Y',
                    formatTime: 'H',
                    dependency: {'element': 'counter_scope', 'value': ['date_time']},
                },
                {
                    type: 'datetime',
                    heading: t('Time'),
                    param_name: 'time',
                    timepicker: true,
                    description: t('Select the time on the day above to which you want to count down to.'),
                    formatTime: 'H',
                    dependency: {'element': 'counter_scope', 'value': ['repeating']},
                },
                {
                    type: 'integer_slider',
                    heading: t('Reset in Hours'),
                    param_name: 'reset_hours',
                    max: 24,
                    description: t('Define the number of hours until countdown reset.'),
                    dependency: {'element': 'counter_scope', 'value': ['resetting']},
                },
                {
                    type: 'integer_slider',
                    heading: t('Reset in Minutes'),
                    param_name: 'reset_minutes',
                    max: 60,
                    description: t('Define the number of minutes until countdown reset.'),
                    dependency: {'element': 'counter_scope', 'value': ['resetting']},
                },
                {
                    type: 'integer_slider',
                    heading: t('Reset in Seconds'),
                    param_name: 'reset_seconds',
                    max: 60,
                    description: t('Define the number of seconds until countdown reset.'),
                    dependency: {'element': 'counter_scope', 'value': ['resetting']},
                },
                {
                    type: 'link',
                    heading: t('Page Referrer'),
                    param_name: 'referrer',
                    description: t('Provide an optional link to another site/page to be opened after countdown expires.'),
                    dependency: {'element': 'counter_scope', 'value': ['repeating', 'resetting']},
                },
                {
                    type: 'checkbox',
                    heading: t('Automatic Restart'),
                    param_name: 'restart',
                    description: t('Switch the toggle if you want to restart the countdown after each expiration.'),
                    value: {
                        'yes': t("Yes, please"),
                    },
                    dependency: {'element': 'counter_scope', 'value': ['resetting']},
                },
                {
                    type: 'saved_datetime',
                    param_name: 'saved',
                },
                {
                    type: 'checkbox',
                    heading: t('Display Options'),
                    param_name: 'display',
                    value: {
                        'days': t("Show Remaining Days"),
                        'hours': t("Show Remaining Hours"),
                        'minutes': t("Show Remaining Minutes"),
                        'seconds': t("Show Remaining Seconds"),
                    },
                },
            ],
            show_settings_on_create: true,
            frontend_render: true,
            showed: function($, p, fp) {

                this.baseclass.prototype.showed.apply(this, arguments);
                var element = this;
                this.add_css('counteverest/css/normalize.css', 'countEverest' in $.fn, function() {
                });
                this.add_css('css/counteverest-main.css', 'countEverest' in $.fn, function() {
                });
                this.add_js_list({
                    paths: ['counteverest/js/vendor/jquery.counteverest.min.js', 'datetimepicker/jquery.datetimepicker.js'],
                    loaded: 'countEverest' in $.fn && 'datetimepicker' in $.fn,
                    callback: function() {
                        var options = {};
                        switch (element.attrs['countdown_style']) {
                            case 'style2':
                                var $example = $(element.dom_element),
                                        $ceDays = $example.find('.ce-days'),
                                        $ceHours = $example.find('.ce-hours'),
                                        $ceMinutes = $example.find('.ce-minutes'),
                                        $ceSeconds = $example.find('.ce-seconds'),
                                        $daysFill = $example.find('.bar-days').find('.fill'),
                                        $hoursFill = $example.find('.bar-hours').find('.fill'),
                                        $minutesFill = $example.find('.bar-minutes').find('.fill'),
                                        $secondsFill = $example.find('.bar-seconds').find('.fill'),
                                        now = new Date(),
                                        then = new Date(now.getTime() + (14 * 24 * 60 * 60 * 1000));
                                function setBar($el, value, max) {
                                    var barWidth = 100 - (100 / max * value);
                                    $el.width(barWidth + '%');
                                }
                                options = {
                                    onChange: function() {
                                        setBar($daysFill, this.days, 365);
                                        setBar($hoursFill, this.hours, 24);
                                        setBar($minutesFill, this.minutes, 60);
                                        setBar($secondsFill, this.seconds, 60);
                                    }
                                }
                                break;
                            case 'style6':
                                function countEverestFlipAnimate($el, data) {
                                    $el.each(function(index) {
                                        var $this = $(this),
                                                $flipFront = $this.find('.ce-flip-front'),
                                                $flipBack = $this.find('.ce-flip-back'),
                                                field = $flipBack.text(),
                                                fieldOld = $this.attr('data-old');
                                        if (typeof fieldOld === 'undefined') {
                                            $this.attr('data-old', field);
                                        }
                                        if (field != fieldOld) {
                                            $this.addClass('animate');
                                            window.setTimeout(function() {
                                                $flipFront.text(field);
                                                $this
                                                        .removeClass('animate')
                                                        .attr('data-old', field);
                                            }, 800);
                                        }
                                    });
                                }
                                if (navigator.userAgent.indexOf('MSIE') !== -1 || navigator.appVersion.indexOf('Trident/') > 0) {
                                    $('html').addClass('internet-explorer');
                                }

                                options = {
                                    hoursWrapper: '.ce-hours .ce-flip-back',
                                    minutesWrapper: '.ce-minutes .ce-flip-back',
                                    secondsWrapper: '.ce-seconds .ce-flip-back',
                                    wrapDigits: false,
                                    onChange: function() {
                                        countEverestFlipAnimate($(element.dom_element).find('.countdown .col>div'), this);
                                    }
                                }
                                break;
                            case 'style7':
                                function countEverestAnimate($el) {
                                    $el.each(function(index) {
                                        var $this = $(this),
                                                fieldText = $this.text(),
                                                fieldData = $this.attr('data-value'),
                                                fieldOld = $this.attr('data-old');

                                        if (typeof fieldOld === 'undefined') {
                                            $this.attr('data-old', fieldText);
                                        }

                                        if (fieldText != fieldData) {

                                            $this
                                                    .attr('data-value', fieldText)
                                                    .attr('data-old', fieldData)
                                                    .addClass('animate');

                                            window.setTimeout(function() {
                                                $this
                                                        .removeClass('animate')
                                                        .attr('data-old', fieldText);
                                            }, 300);
                                        }
                                    });
                                }
                                options = {
                                    onChange: function() {
                                        countEverestAnimate($(element.dom_element).find(".countdown").find('.number span'));
                                    }
                                }
                                break;
                            case 'style9':
                                function deg(v) {
                                    return (Math.PI / 180) * v - (Math.PI / 2);
                                }

                                function drawCircle(canvas, value, max) {
                                    var circle = canvas.getContext('2d');

                                    circle.clearRect(0, 0, canvas.width, canvas.height);
                                    circle.lineWidth = 4;

                                    circle.beginPath();
                                    circle.arc(
                                            canvas.width / 2,
                                            canvas.height / 2,
                                            canvas.width / 2 - circle.lineWidth,
                                            deg(0),
                                            deg(360 / max * (max - value)),
                                            false);
                                    circle.strokeStyle = '#282828';
                                    circle.stroke();

                                    circle.beginPath();
                                    circle.arc(
                                            canvas.width / 2,
                                            canvas.height / 2,
                                            canvas.width / 2 - circle.lineWidth,
                                            deg(0),
                                            deg(360 / max * (max - value)),
                                            true);
                                    circle.strokeStyle = '#117d8b';
                                    circle.stroke();
                                }
                                options = {
                                    leftHandZeros: false,
                                    onChange: function() {
                                        drawCircle($(element.dom_element).find('#days').get(0), this.days, 365);
                                        drawCircle($(element.dom_element).find('#hours').get(0), this.hours, 24);
                                        drawCircle($(element.dom_element).find('#minutes').get(0), this.minutes, 60);
                                        drawCircle($(element.dom_element).find('#seconds').get(0), this.seconds, 60);
                                    }
                                }
                                break;
                            case 'style10':
                                var $countdown = $(element.dom_element).find('.countdown');
                                var firstCalculation = true;
                                options = {
                                    leftHandZeros: true,
                                    dayLabel: null,
                                    hourLabel: null,
                                    minuteLabel: null,
                                    secondLabel: null,
                                    afterCalculation: function() {
                                        var plugin = this,
                                                units = {
                                                    days: this.days,
                                                    hours: this.hours,
                                                    minutes: this.minutes,
                                                    seconds: this.seconds
                                                },
                                        //max values per unit
                                        maxValues = {
                                            hours: '23',
                                            minutes: '59',
                                            seconds: '59'
                                        },
                                        actClass = 'active',
                                                befClass = 'before';

                                        //build necessary elements
                                        if (firstCalculation == true) {
                                            firstCalculation = false;

                                            //build necessary markup
                                            $countdown.find('.unit-wrap div').each(function() {
                                                var $this = $(this),
                                                        className = $this.attr('class'),
                                                        value = units[className],
                                                        sub = '',
                                                        dig = '';

                                                //build markup per unit digit
                                                for (var x = 0; x < 10; x++) {
                                                    sub += [
                                                        '<div class="digits-inner">',
                                                        '<div class="flip-wrap">',
                                                        '<div class="up">',
                                                        '<div class="shadow"></div>',
                                                        '<div class="inn">' + x + '</div>',
                                                        '</div>',
                                                        '<div class="down">',
                                                        '<div class="shadow"></div>',
                                                        '<div class="inn">' + x + '</div>',
                                                        '</div>',
                                                        '</div>',
                                                        '</div>'
                                                    ].join('');
                                                }

                                                //build markup for number
                                                for (var i = 0; i < value.length; i++) {
                                                    dig += '<div class="digits">' + sub + '</div>';
                                                }
                                                $this.append(dig);
                                            });
                                        }

                                        //iterate through units
                                        $.each(units, function(unit) {
                                            var digitCount = $countdown.find('.' + unit + ' .digits').length,
                                                    maxValueUnit = maxValues[unit],
                                                    maxValueDigit,
                                                    value = plugin.strPad(this, digitCount, '0');

                                            //iterate through digits of an unit
                                            for (var i = value.length - 1; i >= 0; i--) {
                                                var $digitsWrap = $countdown.find('.' + unit + ' .digits:eq(' + (i) + ')'),
                                                        $digits = $digitsWrap.find('div.digits-inner');

                                                //use defined max value for digit or simply 9
                                                if (maxValueUnit) {
                                                    maxValueDigit = (maxValueUnit[i] == 0) ? 9 : maxValueUnit[i];
                                                } else {
                                                    maxValueDigit = 9;
                                                }

                                                //which numbers get the active and before class
                                                var activeIndex = parseInt(value[i]),
                                                        beforeIndex = (activeIndex == maxValueDigit) ? 0 : activeIndex + 1;

                                                //check if value change is needed
                                                if ($digits.eq(beforeIndex).hasClass(actClass)) {
                                                    $digits.parent().addClass('play');
                                                }

                                                //remove all classes
                                                $digits
                                                        .removeClass(actClass)
                                                        .removeClass(befClass);

                                                //set classes
                                                $digits.eq(activeIndex).addClass(actClass);
                                                $digits.eq(beforeIndex).addClass(befClass);
                                            }
                                        });
                                    }
                                }
                                break;
                        }
                        switch (element.attrs['counter_scope']) {
                            case 'date':
                                var d = Date.parseDate(element.attrs['date'], 'd.m.Y');
                                if (d != null)
                                    $(element.dom_element).countEverest($.extend(options, {
                                        day: d.getDate(),
                                        month: d.getMonth() + 1,
                                        year: d.getFullYear(),
                                    }));
                                break;
                            case 'date_time':
                                var d = Date.parseDate(element.attrs['date_time'], 'd.m.Y H');
                                if (d != null)
                                    $(element.dom_element).countEverest($.extend(options, {
                                        day: d.getDate(),
                                        month: d.getMonth() + 1,
                                        year: d.getFullYear(),
                                        hour: d.getHours()
                                    }));
                                break;
                            case 'repeating':
                                var d = new Date();
                                d.setHours(element.attrs['time']);
                                if (d != null)
                                    $(element.dom_element).countEverest($.extend(options, {
                                        day: d.getDate(),
                                        month: d.getMonth() + 1,
                                        year: d.getFullYear(),
                                        hour: d.getHours(),
                                        onComplete: function() {
                                            if (element.attrs['referrer'] != '') {
                                                window.location.replace(element.attrs['referrer']);
                                            }
                                        }
                                    }));
                                break;
                            case 'resetting':
                                if (element.attrs['saved'] != '') {
                                    var saved = new Date(element.attrs['saved']);
                                    var interval = (Math.round(element.attrs['reset_hours']) * 60 * 60 + Math.round(element.attrs['reset_minutes']) * 60 + Math.round(element.attrs['reset_seconds'])) * 1000;
                                    if (element.attrs['restart'] == 'yes') {
                                        var current = new Date();
                                        var elapsed = current.getTime() - saved.getTime();
                                        var k = elapsed / interval;
                                        elapsed = elapsed - Math.floor(k) * interval;
                                        var delta = interval - elapsed;
                                        var d = new Date(current.getTime() + delta);
                                        $(element.dom_element).countEverest($.extend(options, {
                                            day: d.getDate(),
                                            month: d.getMonth() + 1,
                                            year: d.getFullYear(),
                                            hour: d.getHours(),
                                            minute: d.getMinutes(),
                                            second: d.getSeconds(),
                                            onComplete: function() {
                                                if (element.attrs['referrer'] != '') {
                                                    window.location.replace(element.attrs['referrer']);
                                                }
                                            }
                                        }));
                                    } else {
                                        var d = new Date(saved.getTime() + interval);
                                        $(element.dom_element).countEverest($.extend(options, {
                                            day: d.getDate(),
                                            month: d.getMonth() + 1,
                                            year: d.getFullYear(),
                                            hour: d.getHours(),
                                            minute: d.getMinutes(),
                                            second: d.getSeconds(),
                                            onComplete: function() {
                                                if (element.attrs['referrer'] != '') {
                                                    window.location.replace(element.attrs['referrer']);
                                                }
                                            }
                                        }));
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                    }});
            },
            render: function($, p, fp) {

                this.dom_element = $('<div class="az-element az-countdown ' + this.attrs['el_class'] + '" style="' + this.attrs['style'] + '"></div>');
                var countdown = $('<div class="countdown"></div>').appendTo(this.dom_element);
                switch (this.attrs['countdown_style']) {
                    case 'style1':
                        $(this.dom_element).addClass('example--1');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<div class="col"><span class="ce-days"></span> <span class="ce-days-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<div class="col"><span class="ce-hours"></span> <span class="ce-hours-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<div class="col"><span class="ce-minutes"></span> <span class="ce-minutes-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<div class="col"><span class="ce-seconds"></span> <span class="ce-seconds-label"></span></div>');
                        break;
                    case 'style2':
                        $(this.dom_element).addClass('example--2');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<div class="bar bar-days"><div class="fill"></div></div><span class="ce-days"></span> <span class="ce-days-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<div class="bar bar-hours"><div class="fill"></div></div><span class="ce-hours"></span> <span class="ce-hours-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<div class="bar bar-minutes"><div class="fill"></div></div><span class="ce-minutes"></span> <span class="ce-minutes-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<div class="bar bar-seconds"><div class="fill"></div></div><span class="ce-seconds"></span> <span class="ce-seconds-label"></span>');
                        break;
                    case 'style3':
                        $(this.dom_element).addClass('example--3');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<span class="number ce-hours"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<span class="number ce-minutes"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<span class="number ce-seconds"></span>');
                        break;
                    case 'style4':
                        $(this.dom_element).addClass('example--4');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<span class="ce-days"></span> <span class="ce-days-label"></span>');
                        break;
                    case 'style5':
                        $(this.dom_element).addClass('example--5');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<span class="ce-minutes"></span>:');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<span class="ce-seconds"></span>');
                        break;
                    case 'style6':
                        $(this.dom_element).addClass('example--6');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<div class="col"><div class="ce-hours"><div class="ce-flip-wrap"><div class="ce-flip-front"></div><div class="ce-flip-back"></div></div></div><span class="ce-hours-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<div class="col"><div class="ce-minutes"><div class="ce-flip-wrap"><div class="ce-flip-front"></div><div class="ce-flip-back"></div></div></div><span class="ce-minutes-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<div class="col"><div class="ce-seconds"><div class="ce-flip-wrap"><div class="ce-flip-front"></div><div class="ce-flip-back"></div></div></div><span class="ce-seconds-label"></span></div>');
                        break;
                    case 'style7':
                        $(this.dom_element).addClass('example--7');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<span class="number ce-hours"></span> :');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<span class="number ce-minutes"></span> :');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<span class="number ce-seconds"></span>');
                        break;
                    case 'style8':
                        $(this.dom_element).addClass('example--8');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<span class="ce-days"></span> <span class="ce-days-label"></span>');
                        break;
                    case 'style9':
                        $(this.dom_element).addClass('example--9');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<div class="circle"><canvas id="days" width="408" height="408"></canvas><div class="circle__values"><span class="ce-digit ce-days"></span><span class="ce-label ce-days-label"></span></div></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<div class="circle"><canvas id="hours" width="408" height="408"></canvas><div class="circle__values"><span class="ce-digit ce-hours"></span><span class="ce-label ce-hours-label"></span></div></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<div class="circle"><canvas id="minutes" width="408" height="408"></canvas><div class="circle__values"><span class="ce-digit ce-minutes"></span><span class="ce-label ce-minutes-label"></span></div></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<div class="circle"><canvas id="seconds" width="408" height="408"></canvas><div class="circle__values"><span class="ce-digit ce-seconds"></span><span class="ce-label ce-seconds-label"></span></div></div>');
                        break;
                    case 'style10':
                        $(this.dom_element).addClass('example--10');
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<div class="unit-wrap"><div class="days"></div><span class="ce-days-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<div class="unit-wrap"><div class="hours"></div><span class="ce-hours-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<div class="unit-wrap"><div class="minutes"></div><span class="ce-minutes-label"></span></div>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<div class="unit-wrap"><div class="seconds"></div><span class="ce-seconds-label"></span></div>');
                        break;
                    default:
                        if (_.indexOf(this.attrs['display'].split(','), 'days') >= 0)
                            $(countdown).append('<span class="ce-days"></span> <span class="ce-days-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'hours') >= 0)
                            $(countdown).append('<span class="ce-hours"></span> <span class="ce-hours-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'minutes') >= 0)
                            $(countdown).append('<span class="ce-minutes"></span> <span class="ce-minutes-label"></span>');
                        if (_.indexOf(this.attrs['display'].split(','), 'seconds') >= 0)
                            $(countdown).append('<span class="ce-seconds"></span> <span class="ce-seconds-label"></span>');
                        break;
                }
                this.baseclass.prototype.render.apply(this, arguments);
            },
        },
    ];

    if ('azexo_elements' in window) {
        window.azexo_elements = window.azexo_elements.concat(azexo_elements);
    } else {
        window.azexo_elements = azexo_elements;
    }
})(window.jQuery);