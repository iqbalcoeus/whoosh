(function($) {
    var p = '';
    var fp = '';
    if ('azexo_prefix' in window) {
        p = window.azexo_prefix;
        fp = window.azexo_prefix.replace('-', '_');
    }
    window.azexo_composer_widgets = function() {
//        Drupal.behaviors.tokenTree.attach();
//        Drupal.behaviors.tokenDialog.attach();
//        Drupal.behaviors.tokenInsert.attach();
    }
    function azexo_composer_select(options, input) {
        var single_select = '<select>';
        for (var key in options) {
            single_select = single_select + '<option value="' + key + '">"' + options[key] + '"</option>';
        }
        single_select = single_select + '</select>';
        $(input).css('display', 'none');
        var select = $(single_select).insertAfter(input);
        if ($(input).val().length) {
            $(select).append('<option value=""></option>');
            var value = $(input).val();
            if (!$(select).find('option[value="' + value + '"]').length) {
                $(select).append('<option value="' + value + '">"' + value + '"</option>');
            }
            $(select).find('option[value="' + value + '"]').attr("selected", "selected");
        } else {
            $(select).append('<option value="" selected></option>');
        }
        $(select).chosen({
            search_contains: true,
            allow_single_deselect: true,
        });
        $(select).change(function() {
            $(this).find('option:selected').each(function() {
                $(input).val($(this).val());
            });
        });
        $(select).parent().find('.chosen-container').width('100%');
        $('<div><a class="direct-input" href="#">' + Drupal.t("Direct input") + '</a></div>').insertBefore(select).click(function() {
            $(input).css('display', 'block');
            $(select).parent().find('.chosen-container').remove();
            $(select).remove();
            $(this).remove();
        });
        return select;
    }
    window.images_select = function(input, delimiter) {
        $(input).css('display', 'none');
        $(input).wrap('<div class="ac-select-image"></div>');
        var image_styles_input = $('<input type="text" name="image_style" style="display: none">').prependTo($(input).closest('.ac-select-image'));
        $(input).closest('.ac-select-image').prepend('<label>' + Drupal.t('Select Image style') + '</label>');
        $(input).closest('.ac-select-image').prepend('<ul class="preview"></ul>');
        $(input).closest('.ac-select-image').prepend('<button class="ac-select-image ' + p + 'btn ' + p + 'btn-default">' + Drupal.t('Select Image') + '</button>');
        $(input).closest('.ac-select-image').once('mediaBrowserLaunch', function() {
            Drupal.media.popups.getDialogOptions = function() {
                return {
                    buttons: {},
                    dialogClass: 'media-wrapper',
                    modal: true,
                    draggable: true,
                    resizable: true,
                    minWidth: 1200,
                    width: 1200,
                    height: 1000,
                    position: 'center',
                    overlay: {
                        backgroundColor: '#000000',
                        opacity: 0.4
                    },
                    zIndex: 10000,
                    close: function(event, ui) {
                        $(event.target).remove();
                    }
                };
            };

            var multiselect = (delimiter != '');
            globalOptions = {types: ['image'], multiselect: multiselect, activePlugins: ['upload', 'media_default--media_browser_1']};
            //globalOptions = Drupal.media.popups.mediaBrowser.getDefaults();
            //globalOptions.global.activePlugins = 'media.upload_multiple.js';
            //options = Drupal.settings.media.fields[this.id];
            var fidField = $(input);
            var previewField = $(input).closest('.ac-select-image').find('.preview');
            //var removeButton = $('.remove', this);
            //removeButton.show();


            var src = '';
            if (delimiter == '')
                src = $(input).val();
            else
                src = $(input).val().split(delimiter).pop();
            if (src) {
                var parts = src.split('/styles/');
                if (parts.length == 2) {
                    var path = parts[1].split('/');
                    $(image_styles_input).val(path.shift());
                }
            }
            var image_styles_select = azexo_composer_select(Drupal.settings.azexo_composer.image_styles, image_styles_input);
            function make_image_src(src) {
                var q = src.split('?');
                if (q.length > 1) {
                    var params = q[1].split('&');
                    var fid = '';
                    for (i in params) {
                        if (params[i].split('=')[0] == 'fid') {
                            fid = params[i].split('=')[1];
                            break;
                        }
                    }
                    if ($(image_styles_input).val() != '') {
                        $.ajax({
                            type: 'POST',
                            url: Drupal.settings.basePath + '?q=azexo_image_style_url',
                            data: {
                                style: $(image_styles_input).val(),
                                fid: fid
                            },
                            dataType: 'json',
                            async: false,
                            context: this,
                            complete: function(data) {
                                if ('responseJSON' in data)
                                    src = data.responseJSON;
                                else
                                    src = $.parseJSON(data.responseText);
                            },
                        });
                    }
                }
                return src;
            }

            function refresh_value(preview, input) {
                var value = '';
                $(preview).find('li').each(function() {
                    if (value.length == 0) {
                        value = make_image_src($(this).find('img').attr('src'));
                    } else {
                        if (delimiter == '')
                            value = make_image_src($(this).find('img').attr('src'));
                        else
                            value = value + delimiter + make_image_src($(this).find('img').attr('src'));
                    }
                });
                $(input).val(value);
            }
            $(image_styles_select).chosen().change(function() {
                refresh_value(previewField, input);
            });

            // Hide the edit and remove buttons if there is no file data yet.
            if (fidField.val() == '') {
                //removeButton.hide();
            } else {
                var value = fidField.val();
                var previews = '';
                var srcs = [];
                if (delimiter == '')
                    srcs = [value];
                else
                    srcs = value.split(delimiter);
                _.each(srcs, function(url) {
                    previews = previews + '<li class="added"><div class="inner" style="width: 75px; height: 75px; overflow: hidden;text-align: center;">';
                    previews = previews + '<img src="' + url + '">';
                    previews = previews + '</div><a href="#" class="icon-remove"></a></li>';
                });
                previewField.html(previews);
                $(previewField).find('.icon-remove').click(function() {
                    $(this).closest('li').remove();
                    refresh_value(previewField, input);
                });
                $(previewField).sortable({
                    items: 'li',
                    placeholder: 'az-sortable-placeholder',
                    forcePlaceholderSize: true,
                    over: function(event, ui) {
                        ui.placeholder.attr('class', ui.helper.attr('class'));
                        ui.placeholder.attr('width', ui.helper.attr('width'));
                        ui.placeholder.attr('height', ui.helper.attr('height'));
                        ui.placeholder.removeClass('ui-sortable-helper');
                        ui.placeholder.addClass('az-sortable-placeholder');
                    },
                    update: function() {
                        refresh_value(previewField, input);
                    },
                });
            }

            // When someone clicks the link to pick media (or clicks on an existing thumbnail)
            $(input).closest('.ac-select-image').find('button.ac-select-image').bind('click', function(e) {
                // Launch the browser, providing the following callback function
                // @TODO: This should not be an anomyous function.
                var mediaIframe = Drupal.media.popups.mediaBrowser(function(mediaFiles) {
                    if (mediaFiles.length < 0) {
                        return;
                    }
                    var fids = '';
                    var previews = '';
                    if (multiselect) {
                        fids = fidField.val();
                        previews = previewField.html();
                    }
                    _.each(mediaFiles, function(mediaFile) {
                        //previews = previews + mediaFile.preview;
                        previews = previews + '<li class="added"><div class="inner" style="width: 75px; height: 75px; overflow: hidden;text-align: center;">';
                        previews = previews + '<img src="' + mediaFile.url + '?fid=' + mediaFile.fid + '">';
                        previews = previews + '</div><a href="#" class="icon-remove"></a></li>';
                    });
                    previewField.html(previews);
                    refresh_value(previewField, input);
                    $(previewField).find('.icon-remove').click(function() {
                        $(this).closest('li').remove();
                        refresh_value(previewField, input);
                    });
                    $(previewField).sortable({
                        items: 'li',
                        placeholder: 'az-sortable-placeholder',
                        forcePlaceholderSize: true,
                        over: function(event, ui) {
                            ui.placeholder.attr('class', ui.helper.attr('class'));
                            ui.placeholder.attr('width', ui.helper.attr('width'));
                            ui.placeholder.attr('height', ui.helper.attr('height'));
                            ui.placeholder.removeClass('ui-sortable-helper');
                            ui.placeholder.addClass('az-sortable-placeholder');
                        },
                        update: function() {
                            refresh_value(previewField, input);
                        },
                    });

                    fidField.trigger('change');
                }, globalOptions);
                e.preventDefault();
                var last_tab_id = '';
                $(mediaIframe).load(function() {
                    var zindex = parseInt($('#az-editor-modal').css('z-index'));
                    $(mediaIframe).parent().css('z-index', zindex + 1);

                    var interval = setInterval(function() {
                        if (document.getElementById('mediaBrowser') != null && $(mediaIframe).dialog("isOpen")) {
                            $(mediaIframe).css('height', $(mediaIframe).contents().height());
                            var exist = false;
                            $(mediaIframe).contents().find('.media-browser-tab').each(function() {
                                if ($(this).attr('aria-expanded') == 'true') {
                                    $(this).css('display', 'block');
                                    last_tab_id = $(this).attr('id');
                                    exist = true;
                                } else {
                                    $(this).css('display', 'none');
                                }
                            });
                            if (!exist) {
                                $(mediaIframe).contents().find('#' + last_tab_id).css('display', 'block');
                            }
                        } else {
                            clearInterval(interval);
                        }
                    }, 100);
                    $(mediaIframe).contents().find('[aria-controls="media-tab-youtube"]').remove();
                    $(mediaIframe).contents().find('#media-tab-youtube').remove();
                    $(mediaIframe).contents().find('[aria-controls="media-tab-media_internet"]').remove();
                    $(mediaIframe).contents().find('#media-tab-media_internet').remove();
                    $(mediaIframe).dialog("option", "closeOnEscape", true);
                });
                return false;
            });

            // When someone clicks the Remove button.
            $('.remove', this).bind('click', function(e) {
                // Set the value of the filefield fid (hidden) and trigger change.
                fidField.val('');
                fidField.trigger('change');
                // Set the preview field HTML.
                previewField.html('');
                e.preventDefault();
            });

            // Show or hide the edit/remove buttons if the field has a file or not.
            $('.fid', this).bind('change', function() {
                if (fidField.val() == '') {
                    //removeButton.hide();
                } else {
                    //removeButton.show();
                }
            });
        });
    }
    window.links_select = function(input, delimiter) {
        Drupal.linkit.registerDialogHelper('ac_linkit', {
            init: function() {
            },
            afterInit: function() {
            },
            insertLink: function(data) {
                if (delimiter == '')
                    $(input).val(Drupal.settings.basePath + data.path);
                else
                    $(input).val($(input).val() + delimiter + Drupal.settings.basePath + data.path);
            },
        });
        $(input).wrap('<div class="ac-link"></div>');
        $(input).closest('.ac-link').prepend('<button class="ac-link-build ' + p + 'btn ' + p + 'btn-default">' + Drupal.t('Add Link') + '</button>');
        $(input).closest('.ac-link').find('.ac-link-build').click(function(e) {
            e.preventDefault();
            var $self = $(this),
                    $block = $(this).closest('.ac-link'),
                    $link_submit = $('#ac-link-submit'),
                    $ac_link_submit = $('<input type="submit" name="ac-link-submit" id="ac-link-submit" class="' + p + 'btn ' + p + 'button-primary" value="Set Link">');
            $link_submit.hide();
            $("#ac-link-submit").remove();
            $ac_link_submit.insertBefore($link_submit);

            Drupal.settings.linkit.currentInstance.profile = 'azexo_composer';
            Drupal.settings.linkit.currentInstance.helper = 'ac_linkit';
            Drupal.settings.linkit.currentInstance.source = $block;
            Drupal.settings.linkit.currentInstance.suppressProfileChanger = true;

            Drupal.linkit.createModal();

            var zindex = parseInt($('#az-editor-modal').css('z-index'));
            $('.linkit-wrapper').css('z-index', zindex + 1);
        });
    }
    window.azexo_tinymce = function(textarea) {        
        function tinymce_add_editor() {
            var id = $(textarea).attr('id');
            if (tinymce.majorVersion == 4)
                tinymce.execCommand('mceAddEditor', false, id);
            if (tinymce.majorVersion == 3)
                tinymce.execCommand('mceAddControl', false, id);
            tinymce.execCommand('mceFocus', false, id);
        }
        if ('tinymce' in window) {
            tinymce_add_editor();
        } else {
            window.azexo_add_js({
                path: 'tinymce/tinymce.min.js',
                callback: function() {
                    if (_.isObject(tinymce)) {
                        var tinymce_config = {
                            theme: "modern",
                            force_br_newlines: false,
                            force_p_newlines: false,
                            forced_root_block: '',
                            plugins: [
                                "advlist autolink link image lists charmap print preview hr anchor pagebreak",
                                "searchreplace wordcount visualblocks visualchars insertdatetime media nonbreaking",
                                "table contextmenu directionality emoticons paste textcolor"
                            ],
                            toolbar1: "undo redo | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | styleselect",
                            toolbar2: "| link unlink anchor | image media | forecolor backcolor  | print preview code ",
                            image_advtab: true,
                        };
                        tinymce.init(tinymce_config);
                        tinymce_add_editor();
                    }
                }});
        }
    }
    window.azexo_t = function(text) {
        return Drupal.t(text);
    }
    if ('azexo_lang' in window)
        if (window.azexo_lang == 'und' || window.azexo_lang == '') {
            delete window.azexo_lang;
        }
    window.azexo_editable = ['h1', 'h2', 'h3', 'h4', 'h5', 'h6', 'img:not(.not-editable)', 'a:not(.not-editable)', 'i:not(.not-editable)'];
    window.azexo_styleable = [];
    window.azexo_textareas = [];
    window.azexo_formats = [];
    Drupal.behaviors.azexo_composer = {
        attach: function(context, settings) {
            if (fp + 'modal' in $.fn && fp + 'popover' in $.fn) {
                for (var i = 0; i < window.azexo_textareas.length; i++) {
                    (function(textarea, format) {
                        $('#' + format).change(function() {
                            if ($(this).val() == 'azexo_composer') {
                                $('#' + textarea).azexo_composer();
                            } else {
                                $('#' + textarea).azexo_composer('hide');
                            }
                        });
                        _.defer(function() {
                            if (_.isUndefined($('#' + textarea).data('azexo_composer'))) {
                                $('#' + format).trigger('change');
                            }
                        });
                    })(window.azexo_textareas[i], window.azexo_formats[i]);
                }
            }
        }
    };
})(jQuery);