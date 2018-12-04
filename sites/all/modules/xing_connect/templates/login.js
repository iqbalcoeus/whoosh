window.xing = window.xing || {},
    function(a, b, c) {
        "use strict";

        function d(a) {
            return this.plugins = [], this.consumers = [], this.incognitoDisabledCookieName = "xing_plugins_login_with_activated", this
        }

        function e(a, b) {
            a = a || {}, a.resource = {}, this.validateConfigEntry(a, "plugin", ["login", "share", "follow"], "login").validateConfigEntry(a, "language", ["en", "de"], "en").validateConfigEntry(a, "visibleOnRender", [!0, !1], !0), this.config = a, this.node = b, this.content = null
        }

        function f() {
            for (var a = c.getElementsByTagName("script"), b = 0, d = /login.js$/, e = 0, f = a.length; e < f; e++) d.test(a[e].src) && b++;
            return b
        }

        function g() {
            x && !x.closed && (clearTimeout(w), x.close(), x = void 0)
        }

        function h() {
            s.events.attach(b, "beforeunload", function() {
                g()
            }), A && s.events.attach(b, "unload", function() {
                g()
            })
        }

        function i() {
            if (f() > 1) a.multipleLibrariesWarning || (s.log(r.TOO_MANY_LIBRARIES, "warn"), a.multipleLibrariesWarning = !0);
            else {
                if (a.initialized && a.initialized.lwx) return;
                a.initialized.lwx = !0, z.init(y), h()
            }
        }

        function j(a, b) {
            b = b || null, z.logoutUser(a, b)
        }
        var k = {
                auth: "/spi/consumers/[consumer_key]/auth/v1/authorize",
                logout: "/auth/v1/logout",
                messageProxy: "/spi/consumers/[consumer_key]/message_proxy",
                plugins: {
                    login: {
                        user: "/plugins/login/v1/user"
                    }
                }
            },
            l = {
                width: 760,
                height: 578,
                title: "XING"
            },
            m = {
                host: "https://www.xing-share.com",
                login: {
                    css: "/plugins/css/spi-button.css?v",
                    js: "/plugins/login.js"
                }
            },
            n = ["permalink"],
            o = {
                libraryURL: "https://www.xing.com/js/sc.js",
                trackingTypes: {
                    userClick: {
                        "s.pageName": "lo/socialplugins/login/xing_home",
                        "s.channel": "social_plugins",
                        "s.prop57": "b6225_login_with_xing",
                        "s.eVar57": "D=c57",
                        "s.prop16": "logged_out",
                        "s.eVar16": "D=c16"
                    },
                    authLogin: {
                        "s.pageName": "li/socialplugins/login/xing_home/direct",
                        "s.channel": "social_plugins",
                        "s.prop16": "logged_in",
                        "s.products": ";direct_b6225_login_with_xing;1"
                    }
                }
            },
            p = "Login with XING",
            q = " | ",
            r = {
                INVALID_CONSUMER: [p, "The Login with XING plugin on this page is using a consumer key which was not configured for this domain. Please use the correct consumer key for this domain or generate a plugin for your domain."].join(q),
                TOO_MANY_LWX: [p, "Multiple Login with XING plugins detected. Only the the first will be initialised."].join(q),
                TOO_MANY_LIBRARIES: [p, "Multiple Login with XING libraries detected. Please make sure you load it only once."].join(q)
            },
            s = {};
        s = s || {}, s.capitalize = function(a) {
            return a.charAt(0).toUpperCase() + a.slice(1)
        }, s = s || {}, s.cloneObject = function(a) {
            return JSON.parse(JSON.stringify(a))
        }, s = s || {}, s.cookies = {
            expirationMultiplier: 86400,
            all: function() {
                var a, b, d, e = {},
                    f = 0;
                if ("" === c.cookie) return {};
                for (a = c.cookie.split("; "), b = a.length; f < b; f++) d = a[f].split("="), e[decodeURIComponent(d[0])] = decodeURIComponent(d[1]);
                return e
            },
            get: function(a) {
                var b = this.all();
                return b[a]
            },
            set: function(a, b, d) {
                var e = "";
                d = d || "", "string" == typeof d && "" !== d ? d = new Date(d) : "number" == typeof d && (d = new Date(+new Date + 1e3 * this.expirationMultiplier * d)), "" !== d && (e = ";expires=", e += "toGMTString" in d ? d.toGMTString() : d), c.cookie = [a, "=", b, e].join("")
            },
            remove: function(a) {
                c.cookie = [a, "=;expires=Thu, 01 Jan 1970 00:00:00 GMT"].join("")
            }
        }, s = s || {}, s.decimalToHex = function(a) {
            return a.toString(16)
        }, s = s || {}, s.decodeQuery = function(a) {
            var b, c, d = {},
                e = a.split("&");
            for (b = 0; b < e.length; b += 1) c = e[b].split("=", 2), c && c[0] && (d[decodeURIComponent(c[0])] = decodeURIComponent(c[1]));
            return d
        }, s = s || {}, s.htmlEncodeJson = function(a, b) {
            var c;
            b = b || [];
            for (c in a) a.hasOwnProperty(c) && s.indexOf(b, c) === -1 && ("string" == typeof a[c] ? a[c] = this.htmlEncode(a[c]) : this.htmlEncodeJson(a[c], b));
            return a
        }, s = s || {}, s.encodeQuery = function(a) {
            var b, c = [];
            for (b in a) a.hasOwnProperty(b) && null !== b && "undefined" != typeof b && c.push(encodeURIComponent(b) + "=" + encodeURIComponent(a[b]));
            return c.join("&")
        }, s = s || {}, s.environment = function(a, b) {
            function d(a) {
                if (null === a.match(m + "$")) return null;
                var b = a.match(/xing(-share)?\.com(:\d*)?\//i);
                if (b) {
                    var c = b[0],
                        d = a.split(c)[0] + c;
                    return d.replace(/\/+$/, "")
                }
                return null
            }

            function e() {
                for (var a, e = c.getElementsByTagName("script"), f = 0; f < e.length; f++)
                    if (a = d(e[f].src, m)) {
                        b = a;
                        break
                    } return b
            }

            function f(a) {
                var c = a || b;
                return null !== c.match(/preview\.xing(-share)?\.com$/)
            }

            function g(a) {
                var c = a || b;
                return null !== c.match(/env\.xing\.com$/)
            }

            function h(a) {
                var c = a || b,
                    d = j;
                return f(c) ? d = l : g(c) && (d = k), d
            }

            function i(a) {
                var c, d = "xingcomdev",
                    e = a || h();
                switch (e) {
                    case j:
                        c = "https://www.xing.com", d = "xingcomprod";
                        break;
                    case k:
                        c = b;
                        break;
                    default:
                        c = b.replace(".xing-share.", ".xing.")
                }
                return {
                    STATICS_HOST: b,
                    BACKEND_HOST: c,
                    TRACKING_ACCOUNT: d
                }
            }
            var j = "prod",
                k = "sandbox",
                l = "preview",
                m = a.split("/").pop();
            return e(), {
                PRODUCTION: j,
                SANDBOX: k,
                PREVIEW: l,
                config: i,
                host: e,
                hostFrom: d,
                isPreviewEnvironment: f,
                isSandboxEnvironment: g,
                name: h
            }
        }, s = s || {}, s.events = s.events || {}, s.events.attach = function(a, b, c) {
            var d;
            return a.addEventListener ? d = a.addEventListener(b, c, !1) : a.attachEvent && (d = a.attachEvent("on" + b, c)), d
        }, s.events.detach = function(a, b, c) {
            a.removeEventListener ? a.removeEventListener(b, c, !1) : a.detachEvent && a.detachEvent("on" + b, c)
        }, s = s || {}, s.extend = function(a, b) {
            var c;
            for (c in b) a[c] = b[c];
            return a
        }, s = s || {}, s.getDocumentFrom = function(a) {
            var b = a.contentWindow || a.contentDocument;
            return b && b.document && (b = b.document), b
        }, s = s || {}, s.getDocumentStylesheets = function() {
            return c.styleSheets
        }, s = s || {}, s.getHost = function(a) {
            function b() {
                var a;
                return a = c.createElement("a"), a.href = " ", a.href
            }
            var d, e;
            return a = a || b(), d = a.split("/"), e = d[0] + "//" + d[2] + "/"
        }, s = s || {}, s.htmlEncode = function(a) {
            return String(a).replace(/"/g, "&quot;").replace(/'/g, "&#39;").replace(/</g, "&lt;").replace(/>/g, "&gt;")
        }, s = s || {}, s.indexOf = function(a, b, c) {
            if (c = c || 0, !Array.prototype.indexOf) {
                for (var d = c, e = a.length; d < e; d++)
                    if (a[d] === b) return d;
                return -1
            }
            return a.indexOf(b, c)
        }, s = s || {}, s.log = function(a, c) {
            var d = ["dir", "error", "info", "log", "warn"],
                e = "log";
            c && s.indexOf(d, c) !== -1 || (c = e), b.console && (a = a, b.console[c](a))
        }, s = s || {}, s.noop = function() {}, s = s || {}, s.openPopup = function(a, c, d) {
            var e = {
                    h: 530,
                    w: 570
                },
                f = {
                    h: d.h || e.h,
                    w: d.w || e.w
                },
                g = Math.floor((b.screen.width - f.w) / 2),
                h = Math.floor((b.screen.height - f.h) / 2);
            return b.open(a, c, "toolbar=0, menubar=0, status=0, directories=0, location=0, resizable=1, scrollbars=1, width=" + f.w + ", height=" + f.h + ", top=" + h + ", left=" + g)
        }, s = s || {}, s.parseJson = function(a) {
            try {
                return "string" == typeof a && a ? (a = this.trim(a), /^[\],:{}\s]*$/.test(a.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, "@").replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, "]").replace(/(?:^|:|,)(?:\s*\[)+/g, "")) ? b.JSON && b.JSON.parse ? b.JSON.parse(a) : new Function("return " + a)() : {
                    err: "Invalid JSON config"
                }) : null
            } catch (c) {
                return {
                    err: c
                }
            }
        }, s = s || {}, s.setAttributes = function(a, b) {
            for (var c in b) a.setAttribute(c, b[c])
        }, s = s || {}, s.setStyles = function(a, b) {
            for (var c in b) a.style[c] = b[c]
        }, s = s || {}, s.stringToHex = function(a) {
            var b, c, d = "",
                e = 0;
            for (a = s.trim(a), b = a.length; e < b; e += 1) c = a.charCodeAt(e), d += s.decimalToHex(c);
            return d
        }, s = s || {}, s.styleSheetExists = function(a) {
            var b, c, d = this.getDocumentStylesheets();
            for (b = 0, c = d.length; b < c; b += 1)
                if (d[b].href && d[b].href.match(a)) return !0;
            return !1
        }, s = s || {}, s.subclass = function(a, b, c) {
            function d() {}
            return d.prototype = a.prototype, b.prototype = new d, b.prototype.constructor = b, c && this.extend(b.prototype, c), b
        }, s = s || {}, s.toBool = function(a, b) {
            if ("boolean" == typeof a) return a;
            switch (a.toString().toLowerCase()) {
                case "true":
                case "yes":
                case "1":
                    return !0;
                case "false":
                case "no":
                case "0":
                    return !1;
                default:
                    return b
            }
        }, s = s || {}, s.tracking = function(a, b, d, e) {
            function f(a) {
                var b, c, d = "";
                for (b in a) a.hasOwnProperty(b) && null !== b && "undefined" != typeof b && (c = a[b], d += [b, '="', s.stringToHex(c), '";'].join(""));
                return d
            }

            function g(a) {
                var b = null;
                return a && (b = '<script>var s_account="' + a + '"</script>'), b
            }

            function h() {
                var e, h, i, j, k, l = '<script src="' + b.libraryURL + '" ></script>';
                return e = c.createElement("iframe"), s.setAttributes(e, {
                    width: "1px",
                    height: "1px",
                    style: "display:none",
                    src: "javascript:'<html></html>'"
                }), e.className = "tracking", k = f(b.trackingTypes[a]), i = g(b.account), c.body.appendChild(e), j = ["<", "script>", "window.onload = function() {", k, "var s_code=s.t();if(s_code)document.write(s_code)", "}", "<", "/script>"].join(""), h = ['<!DOCTYPE html><html><head><meta charset="UTF-8">', i, l, "</head><body>", j, "</body></html>"].join(""), s.writeContentToFrame(e, h, !1), d && d(), e
            }

            function i(a, b) {
                a.parentNode.removeChild(a);
                b && b()
            }

            function j() {
                var a = this,
                    b = a.createFrame();
                setTimeout(function() {
                    a.removeFrame(b), e && e()
                }, k)
            }
            var k = 8e3;
            return {
                initialize: j,
                trackingConfigurationToString: f,
                trackingAccountScriptFor: g,
                createFrame: h,
                removeFrame: i
            }
        }, s = s || {}, s.trim = function(a) {
            return String.prototype.trim ? a.trim() : a.replace(/^\s\s*/, "")
        }, s = s || {}, s.writeContentToFrame = function(a, b, c) {
            var d = s.getDocumentFrom(a),
                e = {
                    height: 18,
                    width: 1
                };
            d && (s.setStyles(a, {
                height: [e.height, "px"].join(""),
                visibility: "hidden",
                width: [e.width, "px"].join("")
            }), c && s.events.attach(a, "load", function() {
                setTimeout(function() {
                    s.setIframeDimensions(a)
                }, 50)
            }), d.open(), d.write(b), d.close())
        }, s.setIframeDimensions = function(a) {
            var b = s.getDocumentFrom(a),
                c = {};
            if (b && b.body) {
                var d = b.scrollingElement ? b.scrollingElement : b.body;
                d.scrollWidth > 18 ? (c = {
                    height: Math.floor(d.scrollHeight),
                    width: Math.floor(d.scrollWidth) + 1
                }, a.height = c.height, a.width = c.width, s.setStyles(a, {
                    height: [c.height, "px"].join(""),
                    visibility: "visible",
                    width: [c.width, "px"].join("")
                })) : setTimeout(function() {
                    s.setIframeDimensions(a)
                }, 100)
            }
        }, s = s || {}, s.xdomainEvents = [], s.xdomain = function(a, b, d, e) {
            function f(a) {
                var b = "",
                    c = {};
                if (a) {
                    b = a;
                    try {
                        c = JSON.parse(a)
                    } catch (d) {
                        c = {}
                    }
                }
                return {
                    string: b,
                    json: c
                }
            }

            function g(a) {
                switch (a.json.success) {
                    case "READY":
                        r && i();
                        break;
                    default:
                        e.callback(a.string), k()
                }
            }

            function h(a) {
                var c;
                a.origin === b && (c = f(a.data), c.json.id === o && g(c))
            }

            function i() {
                q.contentWindow.postMessage(JSON.stringify(r), b), r = null
            }

            function j() {
                s.xdomainEvents[o] = function(a) {
                    h(a)
                }, p.attributes.src = l, s.setAttributes(q, p.attributes), s.setStyles(q, p.styles), a.document.getElementsByTagName("body")[0].appendChild(q), s.events.attach(a, "message", s.xdomainEvents[o])
            }

            function k() {
                var b;
                s.events.detach(a, "message", s.xdomainEvents[o]), delete s.xdomainEvents[o], b = a.document.getElementById(o), b.parentNode.removeChild(b)
            }
            var l, m = new Date,
                n = m.getTime(),
                o = "m" + n,
                p = {
                    attributes: {
                        height: 0,
                        id: o,
                        name: o,
                        width: 0
                    },
                    styles: {
                        display: "none",
                        height: 0,
                        width: 0
                    }
                },
                q = a.document.createElement("iframe"),
                r = null;
            l = [b, d, "?", "callback_domain", "=", encodeURIComponent(String(s.getHost()).replace(/^www\./,'')), "&", "id", "=", o].join(""), e.path && (r = {
                path: e.path,
                id: o
            }, e.data && (r.data = e.data), e.method && (r.method = e.method), e.dataType && (r.dataType = e.dataType)), null === c.getElementById(o) && j()
        }, d.prototype = {
            init: function(a) {
                0 === this.plugins.length && (this.plugins = this.collectScripts(a), this.renderPlugins(), this.incognitoIsDisabled() && this.checkStatusForConsumers())
            },
            incognitoIsDisabled: function() {
                return s.cookies.get(this.incognitoDisabledCookieName)
            },
            collectScripts: function() {
                var a, b, d, e, f, g, h = [];
                for (a = c.getElementsByTagName("script"), b = 0, d = a.length; b < d; b++) e = a[b], e.type && "xing/login" === e.type.toLowerCase() && s.trim(e.innerHTML) && (g = JSON.parse(e.innerHTML), f = new t(g, e), h.push(f));
                return h
            },
            checkStatusForConsumers: function() {
                var a, b = this.plugins,
                    c = this.consumers,
                    d = 0,
                    e = function() {};
                for (a = b.length; d < a; d++) {
                    var f = b[d];
                    s.indexOf(c, f.config.consumer_key) === -1 && (c.push(f.config.consumer_key), u.request(k.plugins.login.user, "get", {
                        consumer_key: f.config.consumer_key
                    }, e, !0))
                }
            },
            renderPlugins: function() {
                var a = this.plugins;
                a && a[0] && a[0].render(), a.length > 1 && s.log(r.TOO_MANY_LWX, "warn")
            },
            logoutUser: function(a, b) {
                function c(b) {
                    u.request(k.logout, "post", {
                        consumer_key: b
                    }, a)
                }
                var d, e, f, g = this.plugins,
                    h = 0;
                if (b) c(b);
                else
                    for (f = g.length; h < f; h++) d = g[h], e = d.config.consumer_key, c(e);
                s.cookies.remove(this.incognitoDisabledCookieName)
            }
        }, e.prototype = {
            rendered: !1,
            extendConfigTo: function(a) {
                return s.extend(a, this), this
            },
            render: function() {
                var a, b, d = this,
                    e = d.node,
                    f = '<link type="text/css" rel="stylesheet" href="' + d.config.resource.css + '">';
                !d.rendered && e.parentNode && (a = c.createElement("iframe"), s.setAttributes(a, {
                    allowTransparency: !0,
                    frameBorder: "none",
                    seamless: "seamless",
                    scrolling: "no",
                    src: "javascript:'<html></html>'"
                }), s.setStyles(a, {
                    background: "transparent",
                    border: "none",
                    padding: "0"
                }), e.parentNode.insertBefore(a, e), e.parentNode.removeChild(e), b = '<!DOCTYPE html><html><head><meta charset="utf-8">' + f + '</head><body><div class="spi-wrapper">' + d.config.resource.html + "</div></body></html>", s.writeContentToFrame(a, b, d.config.visibleOnRender), d.frame = a, d.frameDocument = s.getDocumentFrom(d.frame), d.rendered = !0, d.attachEvents())
            },
            validateConfigEntry: function(a, b, c, d, e) {
                return (a[b] && c && s.indexOf(c, a[b]) === -1 || !a[b]) && (a[b] = d), this
            },
            attachEvents: function() {
                return this
            }
        };
        var t = s.subclass(e, function(a, b) {
            function d() {
                var a;
                return a = c.createElement("a"), a.href = " ", a.href
            }
            a = a || {}, e.call(this, a, b), a.color = this.translateColorConfig(a.color), this.validateConfigEntry(a, "size", ["small", "medium", "large", "xlarge"], "medium").validateConfigEntry(a, "color", ["green", "grey"], "green").validateConfigEntry(a, "consumer_key").validateConfigEntry(a, "onAuthLogin", null, "onXingAuthLogin", !0).validateConfigEntry(a, "onAuthLogout", null, "onXingAuthLogout", !0), a.callback_url = d(), s.extend(a.resource, this.pluginProperties[a.size.toLowerCase()]), a.resource.css = B.STATICS_HOST + this.pluginProperties.css, a.resource.html = this.pluginProperties.html.replace(/<%text%>/g, this.i18n[a.language].text).replace(/<%title%>/g, this.i18n[a.language].title).replace(/<%color%>/g, a.color).replace(/<%language%>/g, a.language).replace(/<%size%>/g, a.size), this.config = a, v.subscribe("authLogin", a.onAuthLogin), v.subscribe("authLogout", a.onAuthLogout)
        }, {
            pluginProperties: {
                css: m.login.css,
                js: m.login.js,
                html: '<div id="xing-login" class="spi-button spi-button-<%color%> <%language%> spi-button-<%size%>" title="<%title%>"><i></i><%text%></div>'
            },
            i18n: {
                en: {
                    text: "Log in",
                    title: "Click to activate the button. We'll remember your choice to log you in automatically on later visits."
                },
                de: {
                    text: "Anmelden",
                    title: "Per Klick aktivieren Sie diesen Button. NÃ¤chstes Mal werden Sie dann automatisch eingeloggt."
                }
            },
            attachEvents: function() {
                function a() {
                    var a;
                    u.request("/authorize", "get", d.config), s.cookies.set("xing_plugins_login_with_activated", 1, 365), setTimeout(function() {
                        o.account = B.TRACKING_ACCOUNT, a = s.tracking("userClick", o), a.initialize()
                    }, 500)
                }

                function b() {
                    e.getElementById("xing-login") && (s.events.attach(e.getElementById("xing-login"), "click", a), clearInterval(c))
                }
                var c, d = this,
                    e = d.frameDocument;
                return c = setInterval(b, 100), d
            },
            translateColorConfig: function(a) {
                return "gray" === a ? "grey" : a
            }
        });
        u = {
            PLUGIN_SCOPE: "xing-lw",
            getSignatureCookieName: function(a) {
                var b = "xing_p_lw_s_";
                return b + a
            },
            storeSignature: function(a, b) {
                var c = u.getSignatureCookieName(a);
                s.cookies.set(c, b)
            },
            removeSignature: function(a) {
                var b = u.getSignatureCookieName(a);
                s.cookies.remove(b)
            },
            authURL: function(a) {
                var b;
                if (a) return b = k.auth.replace("[consumer_key]", a), [B.BACKEND_HOST, b].join("")
            },
            xdomainPath: function(a) {
                if (a) return k.messageProxy.replace("[consumer_key]", a)
            },
            formatResponse: function(a) {
                var b = {
                    user: null,
                    error: null
                };
                if ("object" !== (typeof a).toLowerCase()) try {
                    a = JSON.parse(a)
                } catch (c) {
                    b.error = "INVALID_RESPONSE_FORMAT"
                }
                return a.error ? b.error = a.error : a.users && (a.users[0].signature ? b.user = s.htmlEncodeJson(a.users[0], n) || null : b.error = "NO_SIGNATURE_AVAILABLE"), b
            },
            request: function(a, c, d, e, f) {
                var g, h, i = this,
                    j = !1;
                d.consumer_key && ("/authorize" === a.toLowerCase() ? i.authorize(d, e) : (g = i.xdomainPath(d.consumer_key), h = {
                    path: a,
                    scope: i.PLUGIN_SCOPE,
                    method: c.toUpperCase() || void 0
                }, a.toLowerCase() === k.plugins.login.user ? (j = !0, h.callback = function(a) {
                    f = f || !1, i.processUserResponse(d.consumer_key, a, e, f)
                }) : a.toLowerCase() === k.logout && (j = !0, h.callback = function() {
                    i.processDeleteTokenResponse(d.consumer_key, e)
                }), j && new s.xdomain(b, B.BACKEND_HOST, g, h)))
            },
            authorize: function(a, b) {
                var c, d, e = this;
                c = e.authURL(a.consumer_key), d = {
                    callback_url: a.callback_url
                }, c += "?" + s.encodeQuery(d), x && !x.closed ? (x.location.href = c, x.focus()) : x = s.openPopup(c, l.title, {
                    w: l.width,
                    h: l.height
                }), e.waitForPopup(a.consumer_key), b && v.monitor("authLogin", b), v.fire("authBegin")
            },
            waitForPopup: function(a) {
                var b = this;
                x && !x.closed ? w = setTimeout(function() {
                    b.waitForPopup(a)
                }, 250) : b.processAuthorizeResponse(a)
            },
            processAuthorizeResponse: function(a) {
                var b = this;
                b.request(k.plugins.login.user, "get", {
                    consumer_key: a
                })
            },
            processUserResponse: function(a, b, c, d) {
                var e, f = this;
                d = d || !1, b = f.formatResponse(b), b.error ? (r[b.error] && s.log(r[b.error], "warn"), f.removeSignature(a)) : b.user && (d || (e = s.tracking("authLogin", o), e.initialize()), b.user.signature && (f.storeSignature(a, b.user.signature), delete b.user.signature)), v.fire("authLogin", b), c && c(b)
            },
            processDeleteTokenResponse: function(a, b) {
                v.fire("authLogout", null), u.removeSignature(a), b && "function" == typeof b && b()
            }
        }, v = {
            subscribers: {
                authBegin: [],
                authLogin: [],
                authLogout: []
            },
            subscribe: function(a, b) {
                var c = this.subscribers[a];
                "undefined" != typeof c && s.indexOf(c, b) === -1 && c.push(b)
            },
            unsubscribe: function(a, b) {
                var c = this.subscribers[a],
                    d = s.indexOf(c, b);
                d !== -1 && (c[d] = null)
            },
            monitor: function(a, b) {
                var c = this,
                    d = function(e) {
                        c.unsubscribe(a, d), b(e)
                    };
                c.subscribe(a, d)
            },
            fire: function(a, c) {
                var d, e, f = this.subscribers[a];
                if (f)
                    for (d = 0, e = f.length; d < e; d++) "function" == typeof b[f[d]] ? b[f[d]](c) : "function" == typeof f[d] && f[d](c)
            }
        };
        var u, v, w, x, y = [],
            z = new d,
            A = !!navigator.userAgent.match(/(iPad|iPhone|iPod)/g),
            B = s.environment(m.login.js, m.host).config();
        a.initialized = a.initialized || {
            lwx: !1
        }, a.callbacks = a.callbacks || [], a.logout = a.logout || j, "complete" !== c.readyState ? s.events.attach(b, "load", i) : i()
    }(window.xing, window, document);
